#ifndef JCSV
#define JCSV


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*csv parse*/

#ifndef INIT_SIZE
	#define INIT_SIZE 100
#endif

#ifndef BUFF_SIZE
	#define BUFF_SIZE 2048
#endif

typedef struct data Data;

struct data
{
	int rig,col;
	size_t len;
	char *string;

};

int get_column(Data *);
int get_rig(Data *);
char *get_value(Data *);

Data *csvread(FILE *);

void free_mem(Data **);

int serialize(FILE *);


#endif
