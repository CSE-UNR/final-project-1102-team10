//Joshua Hovatter
//8/12/2024

#include <stdio.h>

void openRead();
void openWrite();

int main(void){

	openRead();
	
	return 0;
}

void openRead(){
	FILE* filePointer;
	filePointer = fopen("madlib1.txt", "r");
	if (filePointer == NULL) {
		printf("Error opening the file!");
    	}
}

void openWrite(){
	FILE* filePointer;
	filePointer = fopen("madlib1.txt", "w");
	if (filePointer == NULL) {
		printf("Error opening the file!");
	}
}
