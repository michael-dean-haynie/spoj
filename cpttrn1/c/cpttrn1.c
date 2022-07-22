#include <stdio.h>

int main(void) {
	int tests = 0;
	scanf("%d", &tests);

	for(int test = 0; test < tests; test++) {
		int rows = 0;
		int cols = 0;
		scanf("%d %d", &rows, &cols);

		char chars[2] = { '*', '.' };
		
		for(int row = 0; row < rows; row++) {
			int isOddRow = (row % 2);
			for(int col = 0; col < cols; col++) {
				char ci = (isOddRow)^(col % 2); // invert odd rows
				printf("%c", chars[ci]);
			}
			printf("\n");
		}
		if (test+1 < tests) {
			printf("\n");
		}
	}

	return 0;
}
