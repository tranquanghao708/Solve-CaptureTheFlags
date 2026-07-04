#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int checker(char *number){
	if(*number == '\0') return 0;

	if(*number == '-') number++;

	while(*number){
		if(*number < '0' || *number > '9'){
			return 1;
		}
		*number++;
	}
	return 0;
}

int main(int argc , char **argv){
	if(argv[1] == NULL) return -1;

	if(checker(argv[1]) == 1) return -1;

	long long y = atoll(argv[1]); //0110..
	int x = (int)y; // 10..

	if ((long long)x != y){ //11110.. != 0110.. -> true 
		printf("Flags\n");
	}

	printf("thanks\n");
	return 0;
}

