/*
    UF_IPMC/toml.h

    Original work Copyright (c) 2017 - 2019 CK Tan (MIT License)
    https://github.com/cktan/tomlc99

    Modified work Copyright 2020 Aleksei Greshilov
    aleksei.greshilov@cern.ch

    UF_IPMC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    UF_IPMC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with UF_IPMC.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef TOML_H
#define TOML_H


#include <stdio.h>
#include <stdint.h>


#ifdef __cplusplus
#define TOML_EXTERN extern "C"
#else
#define TOML_EXTERN extern
#endif

typedef struct toml_table_t toml_table_t;
typedef struct toml_array_t toml_array_t;

/* A raw value, must be processed by toml_rto* before using. */
typedef const char* toml_raw_t;

/* Parse a file. Return a table on success, or 0 otherwise. 
 * Caller must toml_free(the-return-value) after use.
 */
TOML_EXTERN toml_table_t* toml_parse_file(FILE* fp, 
										  char* errbuf,
										  int errbufsz);

/* Parse a string containing the full config. 
 * Return a table on success, or 0 otherwise.
 * Caller must toml_free(the-return-value) after use.
 */
TOML_EXTERN toml_table_t* toml_parse(char* conf, /* NUL terminated, please. */
									 char* errbuf,
									 int errbufsz);

/* Free the table returned by toml_parse() or toml_parse_file(). */
TOML_EXTERN void toml_free(toml_table_t* tab);

/* Retrieve the key in table at keyidx. Return 0 if out of range. */
TOML_EXTERN const char* toml_key_in(const toml_table_t* tab, int keyidx);

/* Lookup table by key. Return the element or 0 if not found. */
TOML_EXTERN toml_raw_t toml_raw_in(const toml_table_t* tab, const char* key);
TOML_EXTERN toml_array_t* toml_array_in(const toml_table_t* tab,
										const char* key);
TOML_EXTERN toml_table_t* toml_table_in(const toml_table_t* tab,
										const char* key);

/* Return the array kind: 't'able, 'a'rray, 'v'alue */
TOML_EXTERN char toml_array_kind(const toml_array_t* arr);

/* For array kind 'v'alue, return the type of values 
   i:int, d:double, b:bool, s:string, t:time, D:date, T:timestamp
   0 if unknown
*/
TOML_EXTERN char toml_array_type(const toml_array_t* arr);


/* Return the number of elements in the array */
TOML_EXTERN int toml_array_nelem(const toml_array_t* arr);

/* Return the key of an array */
TOML_EXTERN const char* toml_array_key(const toml_array_t* arr);

/* Return the number of key-values in a table */
TOML_EXTERN int toml_table_nkval(const toml_table_t* tab);

/* Return the number of arrays in a table */
TOML_EXTERN int toml_table_narr(const toml_table_t* tab);

/* Return the number of sub-tables in a table */
TOML_EXTERN int toml_table_ntab(const toml_table_t* tab);

/* Return the key of a table*/
TOML_EXTERN const char* toml_table_key(const toml_table_t* tab);

/* Deref array by index. Return the element at idx or 0 if out of range. */
TOML_EXTERN toml_raw_t toml_raw_at(const toml_array_t* arr, int idx);
TOML_EXTERN toml_array_t* toml_array_at(const toml_array_t* arr, int idx);
TOML_EXTERN toml_table_t* toml_table_at(const toml_array_t* arr, int idx);

/* Raw to String. Caller must call free(ret) after use. 
 * Return 0 on success, -1 otherwise.
 */
TOML_EXTERN int toml_rtos(toml_raw_t s, char** ret);

/* Raw to Boolean. Return 0 on success, -1 otherwise. */
TOML_EXTERN int toml_rtob(toml_raw_t s, int* ret);

/* Raw to Integer. Return 0 on success, -1 otherwise. */
TOML_EXTERN int toml_rtoi(toml_raw_t s, int64_t* ret);

/* Raw to Double. Return 0 on success, -1 otherwise. */
TOML_EXTERN int toml_rtod(toml_raw_t s, double* ret);

/* Same as toml_rtod, but return the sanitized double in string form as well */
TOML_EXTERN int toml_rtod_ex(toml_raw_t s, double* ret, char* buf, int buflen);

/* Timestamp types. The year, month, day, hour, minute, second, z 
 * fields may be NULL if they are not relevant. e.g. In a DATE
 * type, the hour, minute, second and z fields will be NULLs.
 */
typedef struct toml_timestamp_t toml_timestamp_t;
struct toml_timestamp_t {
	struct { /* internal. do not use. */
		int year, month, day;
		int hour, minute, second, millisec;
		char z[10];
	} __buffer;
	int *year, *month, *day;
	int *hour, *minute, *second, *millisec;
	char* z;
};

/* Raw to Timestamp. Return 0 on success, -1 otherwise. */
TOML_EXTERN int toml_rtots(toml_raw_t s, toml_timestamp_t* ret);

/* misc */
TOML_EXTERN int toml_utf8_to_ucs(const char* orig, int len, int64_t* ret);
TOML_EXTERN int toml_ucs_to_utf8(int64_t code, char buf[6]);
TOML_EXTERN void toml_set_memutil(void* (*xxmalloc)(size_t),
								  void	(*xxfree)(void*));

#endif /* TOML_H */
