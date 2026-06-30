/*Thats, EZ two complement code challenge binary*/

#include <stdio.h>
#include <stdlib.h>

int algrothims_numbers_checker(char *numbers){
	if(*numbers == '\0'){
		return -1;
	}

	while(*numbers){
		if(*numbers < '0' || *numbers > '9'){ //tmax int
			return 1;
		}
		*numbers++;
	}
	return 0;
}

int main(int argc, char **argv){

	if(argv[1] == NULL){
		return -1;
	}

	if(algrothims_numbers_checker(argv[1]) == 1){
		return -1;
	}

	int x = atoi(argv[1]);

	if((unsigned int)x > -1){ //Optimized by compiler and false 100%
		printf("your flags: abcdxyz\n");
		return 0;
	}

	printf("thanks\n");

	return 0;
}