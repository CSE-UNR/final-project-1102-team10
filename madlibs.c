#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_LINES 100

void input(FILE *fptr, char template[MAX_ROW][MAX_COL]);
void storage(char template[MAX_ROW][MAX_COL], int lines, char result[MAX_LINES], int *result_count);
void prompt(char single_char_lines[MAX_LINES], int result_count, char user_inputs[MAX_LINES][100]);
void printMadlib(char madlib[MAX_ROW][MAX_COL], int lines);

int main() {
	char template[MAX_ROW][MAX_COL];
	char single_char_lines[MAX_LINES];
	char user_inputs[MAX_LINES][100];
	int result_count = 0;

	FILE *fptr = fopen("madlib1.txt", "r");
	if (fptr == NULL) {
		printf("Failed to open file.\n");
	}

	input(fptr, template);

	int lines = 0;
	while (lines < MAX_ROW && template[lines][0] != '\0') {
        	lines++;
    	}

	storage(template, lines, single_char_lines, &result_count);

    	prompt(single_char_lines, result_count, user_inputs);

   	 for (int i = 0; i < result_count; i++) {
        	for (int j = 0; j < lines; j++) {
            		for (int k = 0; k < MAX_COL && template[j][k] != '\0'; k++) {
                		if (template[j][k] == single_char_lines[i]) {
                    			int input_len = 0;
                    			while (user_inputs[i][input_len] != '\0') {
                        			input_len++;
                    			}
                    			if (k + input_len < MAX_COL) {
                        			for (int m = 0; m < input_len; m++) {
                            				template[j][k + m] = user_inputs[i][m];
                        			}
                    			}
                    			break;
                		}
            		}
        	}
    	}

	printMadlib(template, lines);

	fclose(fptr);

	return 0;
}

void input(FILE *fptr, char template[MAX_ROW][MAX_COL]) {
	int row = 0;
	while (fgets(template[row], MAX_COL, fptr) != NULL && row < MAX_ROW) {
 		int col = 0;
		while (template[row][col] != '\0') {
		col++;
		}
	if (template[row][col - 1] == '\n') {
            template[row][col - 1] = '\0';
        }
        row++;
	}
}

void storage(char template[MAX_ROW][MAX_COL], int lines, char result[MAX_LINES], int *result_count) {
	for (int i = 0; i < lines; i++) {
		if (template[i][0] != '\0' && template[i][1] == '\0') {
			if (template[i][0] != '!') {
				if (*result_count < MAX_LINES) {
					result[*result_count] = template[i][0];
					(*result_count)++;
				}
			}
		}
	}
}

void prompt(char single_char_lines[MAX_LINES], int result_count, char user_inputs[MAX_LINES][100]) {

	char user_input[100];

	for (int i = 0; i < result_count; i++) {
		char placeholder = single_char_lines[i];
		if (placeholder == 'A') {
			printf("Please enter an adjective: ", placeholder);
		}
		else if (placeholder == 'N') {
			printf("Please enter a noun: ", placeholder);
		}
		else if (placeholder == 'V') {
			printf("Please enter a verb: ", placeholder);
		} 

		scanf("%s", user_input);

		int j = 0;
		while (user_input[j] != '\0') {
			user_inputs[i][j] = user_input[j];
			j++;
		}	
    }
}

void printMadlib(char madlib[MAX_ROW][MAX_COL], int lines) {
	printf("\n");
	for (int i = 0; i < lines; i++) {
		printf("%s ", madlib[i]);
    }
	printf("\n");
}

