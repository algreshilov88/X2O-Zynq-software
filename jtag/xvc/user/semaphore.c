#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include "semaphore.h"

#define MAX_DEVICES 20

union semun {
	int val; 
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

int fd_semid[MAX_DEVICES];

int lock_device(int dev_ind)
{
	int sem_id = fd_semid[dev_ind];
	int nsops = 2;
	struct sembuf sops[2];

	/* wait for semaphore to reach zero */
	sops[0].sem_num = 0; /* We only use one track */
	sops[0].sem_op = 0; /* wait for semaphore flag to become zero */
	sops[0].sem_flg = 0;

	sops[1].sem_num = 0;
	sops[1].sem_op = 1; /* increment semaphore -- take control of track */
	sops[1].sem_flg = IPC_NOWAIT; /* take off semaphore */

	if ((semop(sem_id, sops, nsops)) == -1)
	{
		perror("lock semop()");
		return -1;
	}

	return 0;
}

int unlock_device(int dev_ind)
{
	int sem_id = fd_semid[dev_ind];
	int nsops = 1;
	struct sembuf sops[1];

	/* wait for semaphore to reach zero */
	sops[0].sem_num = 0;
	sops[0].sem_op = -1; /* Give UP COntrol of track */
	sops[0].sem_flg = IPC_NOWAIT; /* take off semaphore, asynchronous  */

	if ((semop(sem_id, sops, nsops)) == -1)
	{
		perror("unlock semop()");
		return -1;
	}
	
	/*if ((semctl(sem_id, 0, IPC_RMID)) == -1)
	{
		printf("unlock semctl() failed\n");
		return -1;
	}*/

	return 0;
}

int create_semaphore (int dev_ind)
{
	int semid;
	key_t sem_key;
	int semflg = 0666;
	int nsems = 1;
	union semun arg;
	char j_xvc_sem[50];
	snprintf(j_xvc_sem, 49, "/tmp/jtag_xvc_semaphore_%d.txt", dev_ind);
	char* sem_fn = j_xvc_sem;
	
	FILE* sem_fd = fopen (sem_fn, "wr"); // create a file for semaphore
	if (sem_fd == NULL)
	{
		perror("Open semaphore file");
		return -1;
	}

	/* generate key */
    if ((sem_key = ftok(sem_fn, (char)dev_ind)) == -1)
	{
        printf("ftok() with  dev_ind: %d", dev_ind);
		perror(" ");
		return -2;
	}

    /* set up semaphore */
    if ((semid = semget(sem_key, nsems, semflg)) == -1)
	{
        if (errno == ENOENT)
		{
			if ((semid = semget(sem_key, nsems, 0666 | IPC_CREAT | IPC_EXCL)) == -1)
			{
				perror("(repeat) semget()");
				return -3;
			}
			
			arg.val = 0;

			if ((semctl(semid, 0, SETVAL, arg)) == -1)
			{
				perror("semctl()");
				return -3;
			}
		}
		else
		{
			perror("semget()");
			return -3;
		}
	}

    	fd_semid[dev_ind] = semid; // store semaphore ID in map

	arg.val = 0;

	if ((semctl(semid, 0, SETVAL, arg)) == -1)
	{
		perror("semctl()");
		return -4;
	}
    

	return 0;
}
