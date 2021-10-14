#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include "i2c-chip.h"

using namespace std;

int main(int argc, char * argv[])
{
	u8 i2c_chip = 0x18;

	if (argc == 1) {

	u8 regval_0, regval_1;
	int result;

	i2c_chip_initialize(argc, argv[1]);

	i2c_write(i2c_fd_bus, i2c_chip, 0xff, 0x04);
	i2c_write(i2c_fd_bus, i2c_chip, 0x3e, 0x00);
	i2c_write(i2c_fd_bus, i2c_chip, 0x2c, 0x32);
	i2c_write(i2c_fd_bus, i2c_chip, 0x11, 0x40);
	i2c_write(i2c_fd_bus, i2c_chip, 0x22, 0x00);
	i2c_write(i2c_fd_bus, i2c_chip, 0x24, 0x81);

	for (int i = 0; i < 4; i++) {
		i2c_read(i2c_fd_bus, i2c_chip, 0x25, &regval_0);
		i2c_read(i2c_fd_bus, i2c_chip, 0x26, &regval_1);
	}

  	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
  	time_t now = time(0);
  	struct tm tstruct;
  	char 	 buftime_0[80];
  	char   buftime_1[80];
  	tstruct = *localtime(&now);
  	strftime(buftime_0, sizeof(buftime_0), "%Y-%b-%d_%X", &tstruct);
  	strftime(buftime_1, sizeof(buftime_1), "%Y-%b-%d %X", &tstruct);

  	// Eyescan directory for .csv and .pdf files
  	ostringstream osfolderpath_csv, osfolderpath_png;
  	osfolderpath_csv << getenv("HOME") << "/X2O-Zynq-software/eom/scans/csv";
  	osfolderpath_png << getenv("HOME") << "/X2O-Zynq-software/eom/scans/png";
  	string folderpath_csv = osfolderpath_csv.str();
  	string folderpath_png = osfolderpath_png.str();
 
  	if (!boost::filesystem::is_directory(boost::filesystem::path(folderpath_csv)))
  	{
    		try 
    		{
     	 		boost::filesystem::create_directories(boost::filesystem::path(folderpath_csv));
    		}
    		catch (boost::filesystem::filesystem_error const & e)
    		{
     	 		cerr << e.what() << endl;	
   	 	}  
  	}	

  	if (!boost::filesystem::is_directory(boost::filesystem::path(folderpath_png)))
  	{
   		try
    		{
     		 	boost::filesystem::create_directories(boost::filesystem::path(folderpath_png));
   		}
  		catch (boost::filesystem::filesystem_error const & e)
  		{
  		    	cerr << e.what() << endl;
   		}
  	}

  	// Pre-fill .csv result file.
  	ostringstream osfilename;
  	osfilename << getenv("HOME") << "/X2O-Zynq-software/eom/scans/csv/eom_" << buftime_0 << ".csv";
  	string filename = osfilename.str();
  	ofstream f(filename.c_str(), ios::app);

  	f << "Date and Time Started," << buftime_1  << endl;
  	f << "Scan Name,Eye Opening Monitor" << endl;
  	f << "Dwell,BER" << endl;
  	f << "Dwell BER,1e-5" << endl;
  	f << "Dwell Time,0" << endl;
  	f << "Horizontal Increment,1" << endl;
  	f << "Horizontal Range,-0.500 UI to 0.500 UI" << endl;
  	f << "Vertical Increment,1" << endl;
  	f << "Vertical Range,100%" << endl;
  	f << "Scan Start" << endl;
	f << "2d statistical,";

  	for (int i_horz = 0; i_horz <= 63; i_horz++) {		// iterate horizontal to pre-fill .csv file
    		if (i_horz == 63)
    		{
      			f << i_horz << endl;
    		}
    		else
    		{
      			f << i_horz << ",";
    		}
  	}

  	for (int i_vert = 0; i_vert <= 63; i_vert++) {	// iterate vertical
    		f << i_vert << ",";
    		for (int i_horz = 0; i_horz <= 63; i_horz++) {		// iterate horizontal
				i2c_read(i2c_fd_bus, i2c_chip, 0x25, &regval_0);
                i2c_read(i2c_fd_bus, i2c_chip, 0x26, &regval_1);
                result = (regval_0 << 8) | regval_1;

       			if (i_horz == 63)
       			{
					f << dec << result << endl;
       			}
       			else
       			{
         			f << dec << result << ",";
       			}
    		}
  	}
  	f << "Scan End" << endl;
  	f.close();

	i2c_write(i2c_fd_bus, i2c_chip, 0x3e, 0x80);
	i2c_write(i2c_fd_bus, i2c_chip, 0x2c, 0x72);
	i2c_write(i2c_fd_bus, i2c_chip, 0x11, 0x20);
	i2c_write(i2c_fd_bus, i2c_chip, 0x24, 0x00);
	
	i2c_chip_deinitialize();
	} else {
		printf ("Invalid command!\n");
	}

	return EXIT_SUCCESS;
}
