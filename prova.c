#include "jcsv.h"

int main()
{
	printf("hello im the main\n");

	FILE *pr = fopen("new.csv", "r");

	Data *my = csvread(pr);

	printf("%s %d %d\n",get_value(&my[10]), get_rig(&my[10]), get_column(&my[10]));

	free_mem(&my);

	fclose(pr);


	return 0;

}
