#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int number_checker(char *number){
	if(*number == '\0'){return -1;}
	
	while(*number){
		if(*number < '0' || *number > '9'){
			return 1;
		}
		*number++;
	}
	return 0;
}

int main(int argc, char **argv){
	if(argv[1] == NULL) return -1;

	if(number_checker(argv[1]) == 1) return -1;

	int x = atoi(argv[1]);
	if((unsigned int)x > INT_MAX){
		printf("Flags\n");
		return 0;
	}

	printf("thanks\n");
	return 0;
}
