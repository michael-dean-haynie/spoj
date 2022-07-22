#include <stdio.h>

int main(void) {
	int testCases = 0;
	scanf("%d", &testCases);

	for(int testCase = 0; testCase < testCases; testCase++) {
		int lines = 0;
		int columns = 0;
		scanf("%d %d", &lines, &columns);

		for(int line = 0; line < lines; line++) {
			for(int col = 0; col < columns; col++) {
				char pc = '*';// print character
				if((line > 0 && line < lines -1) && (col > 0 && col < columns - 1)) {
					pc = '.';
				}
				printf("%c", pc);
			}
			printf("\n");
		}

		// add single new line between test cases
		if (testCase < testCases -1) {
			printf("\n");
		}
	}
}
