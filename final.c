//Joshua Hovatter
//8/12/2024

#include <stdio.h>

void openRead();
void oppenWrite();

int main(void){

	openRead();
	return 0;
}

void openRead(){
	FILE* ptr;
	ptr = fopen("madlib1.txt", "r");
	if (ptr == NULL) {
		printf("Error");
    }
}
