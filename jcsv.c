#include "jcsv.h"



Data  *csvread(FILE *pr)
{
		Data *object = (Data *)malloc(16*INIT_SIZE);

		for (size_t i = 0; i < INIT_SIZE; i++)
		{
			object[i].col = object[i].rig = 0;
			object[i].len = 0;
			object[i].string = NULL;
		}
		


		char buff[BUFF_SIZE];
		const char *sep = ",";
		int rig = 0;
		int i = 0;
		while(fgets(buff, BUFF_SIZE, pr))
		{
			
			char *tok;
			int col = 0;
			
			
			for (tok = strtok(buff, sep);
				tok;
				tok = strtok(NULL, sep))
				{
			
					object[i].rig = rig;
					object[i].col = col;
					object[i].string = (char *)malloc(strlen(tok)+1);
					strcpy(object[i].string, tok);
					col++;				
					i++;
				}

				rig++;
				
		}	

		object = realloc((void *)object, sizeof(Data)*i);
		if (!object)
			return NULL;

	return object;
}

void free_mem(Data **my)
{

	for (size_t i = 0; i < INIT_SIZE; i++)
	{
		free((*my)[i].string);
	}
	free(*my);

}

int get_column(Data *d){

	return d->col;

}
int get_rig(Data *d){


	return d->rig;

}
char *get_value(Data *d)
{

	return d->string;

}
