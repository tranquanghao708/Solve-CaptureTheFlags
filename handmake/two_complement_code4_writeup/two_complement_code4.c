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

	int flags = 0;

	__asm__ __volatile__(
		"movl %[x], %%eax\n\t"
		"movl %%eax, %%edi\n\t"
		"negl %%edi\n\t"
		"cmpl %%edi, %%eax\n\t"
		"jne 1f\n\t"

		"testl %%eax, %%eax\n\t"
		"je 1f\n\t" //loại x = 0

		"movl $1, %[flags]\n\t"
		"1:\n\t"
		: [flags] "+r"(flags)
		: [x] "r"(x)
		: "edx","eax", "cc"
	);

	if(flags){
		printf("flags\n");
	}

	printf("thanks\n");
	return 0;
}
