#include <stdio.h>

int main(void){
	unsigned int local_1c; //ko dấu như ghidra

	for(int local_24 = 10000; local_24 <= 2000000; local_24++){
		for(int local_28=10000 ; local_28<=2000000; local_28++){
			if((local_1c = local_24 * local_28) == 0x20){ //vượt miền Umax ở unsigned overflow nếu là 0x20 thì dừng loop
				printf("local_24 = %d\nlocal_28 = %d\nlocal_1c = %d\n",local_24,local_28,local_1c);
				break;
			}
		}
	}
	return 0;
}
