#include <stdio.h>

int main(void) {
	int cases = 0;
	scanf("%d", &cases);

	for(int tc = 0; tc < cases; tc++) { // test case
		int rows = 0, cols = 0, height = 0, width = 0;
		scanf("%d %d %d %d", &rows, &cols, &height, &width);

		int charRows = (rows * (height + 1)) + 1;
		int charCols = (cols * (width + 1)) + 1;

		for(int cr = 0; cr < charRows; cr++) { // character row
			int isHorizontal = (cr % (height + 1)) == 0;
			for(int cc = 0; cc < charCols; cc++) { // character column
				int isVertical = (cc % (width + 1)) == 0;
				printf("%c", (isHorizontal || isVertical) ? '*' : '.');
			}
			printf("\n"); // end of character row
		}
		if (tc < cases -1) { // end of test case (except last one)
			printf("\n");
		}
	}

	return 0;
}
