// exceptgen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define APPLICATION_NAME "exceptgen"

int main(int argc, char *argv[])
{
	float input_float = 0.0;
	float result_float = 0.0;
	int input_int = 0;
	int result_int = 0;
	int *pointer = NULL;

	if (argc <= 2)
	{
		printf("%s usage:\n", APPLICATION_NAME);
		printf("\n");
		printf("%s [-r <address>] [-w <address>] [-r <float>] [-i <int>] [-h]\n", APPLICATION_NAME);
		printf("\n");
		printf(" -r <address>  // read address\n");
		printf(" -w <address>  // write address\n");
		printf(" -f <value>    // divide 1.0 by floating point <value>\n");
		printf(" -i <value>    // divide 1 by integer <value>\n");
		printf(" -h            // help");
		exit(EXIT_SUCCESS);
	}
	switch (tolower(argv[1][1]))
	{
	case ('r'):
		sscanf_s(argv[2], "%d", &input_int);
		pointer = (int *) input_int;
		printf("read from address %d\n", (int)pointer);
		printf("value=%d\n", *pointer);
		break;
	case ('w'):
		sscanf_s(argv[2], "%d", &input_int);
		pointer = (int *)input_int;
		printf("write to address %d\n", (int)pointer);
		*pointer = 1;
		printf("value=%d\n", *pointer);  // will not actually get here
		break;
	case ('f'):
		sscanf_s(argv[2], "%f", &input_float);
		printf("floating point input %f\n", (float)input_float);
		result_float = (float) 1.0 / input_float;
		printf("result : %f\n", result_float);
		break;
	case ('i'):
		sscanf_s(argv[2], "%i", &input_int);
		printf("int input %d\n", input_int);
		result_int = 1 / input_int;
		printf("result : %d\n", result_int);
		break;
	default:
		printf("error : %s\n", argv[1]);
	}
    return 0;
}

