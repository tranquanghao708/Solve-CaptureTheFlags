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

	int x = atoi(argv[1]);

	if ((x ^ (x << 1)) < 0){
		printf("flags\n");
		return 0;
	}

	printf("thanks\n");
	return 0;
}


