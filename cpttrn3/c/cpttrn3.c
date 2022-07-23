//https://www.spoj.com/problems/CPTTRN3/
#include <stdio.h>

int main(void) {
	int cases = 0;
	scanf("%d", &cases);

	for(int tc = 0; tc < cases; tc++) {
		int rows = 0;
		int cols = 0;
		scanf("%d %d", &rows, &cols);

		int charCols = (cols * 3) + 1;
		int charRows = (rows * 3) + 1;

		for(int cr = 0; cr < charRows; cr++) { // character row
			int isHorizontal = cr % 3 == 0;
			for(int cc = 0; cc < charCols; cc++) { // character column
				int isVertical = cc % 3 == 0;
				printf("%c", isHorizontal || isVertical ? '*' : '.');
			}
			printf("\n"); // end of character row
		}
		if (tc < cases -1) { // end of test case (except last test case)
			printf("\n");
		}
	}
	
	return 0;
}
