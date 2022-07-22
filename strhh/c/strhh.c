// https://www.spoj.com/problems/STRHH/
#include <stdio.h>
#include <string.h>

int main() {
	int testCaseCount;
	scanf("%d", &testCaseCount);
	// printf("testCaseCount: %d\n", testCaseCount);
	
	for(int testCase = 1; testCase <= testCaseCount; testCase++) {
		// printf("testCase: %d\n", testCase);
		char string[201];
		scanf("%s", string);
		// printf("%s\n", string);
		
		int stringLength = strlen(string);
		// printf("%d\n", stringLength);

		for(int i = 0; i < (stringLength / 2); i++) {
			if(i % 2 == 0) {
				printf("%c", string[i]);
			}
		}
		printf("\n");
	}


	return 0;
}
