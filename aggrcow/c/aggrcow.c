// https://www.spoj.com/problems/AGGRCOW/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ENABLE_LOGGING = 0;

// see:
// https://stackoverflow.com/a/23842944
// https://www.cprogramming.com/tutorial/c/lesson17.html
// http://unixwiz.net/techtips/gnu-c-attributes.html
void log_out(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

void log_out(const char *format, ...) {
    if (ENABLE_LOGGING == 1) {
        char* string;
        va_list args;

        va_start(args, format);
        if(0 > vasprintf(&string, format, args)) string = NULL;    // this is for logging, so failed allocation is not fatal
        va_end(args);

        if(string) {
            printf("%s", string);
            free(string);
        } else {
            log_out("Error while logging a message: Memory allocation failed.\n");
        }
    }
}

int compare_ints(const void* p, const void* q) {
    int x = *(const int*)p;
    int y = *(const int*)q;
    return (x > y) - (x < y);
}

void logIntArray(int arr[], int arrSize) {
    log_out("[");
    for(int i = 0; i < arrSize; i++) {
        if(i > 0) {
            log_out(", ");
        }
        log_out("%i", arr[i]);
    }
    log_out("]\n");
}

void qsortIntArray(int arr[], int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare_ints);
}

void findMinDistCow(int* minDistPtr, int* minDistCowPosIdxPtr, int cowPositions[], int cowPositionsSize) {
    *minDistPtr = 0;
    for(int i = 0; i < cowPositionsSize - 1; i++) {
        int dist = cowPositions[i + 1] - cowPositions[i];
        if (*minDistPtr == 0 || dist < *minDistPtr) {
            *minDistPtr = dist;
            *minDistCowPosIdxPtr = i + 1;
        }
    }
}

// returns 1 if it found a stall, 0 otherwise
int checkForNewStall(int* newStallPosPtr, int minDist, int cowPositions[], int cowCount, int stallPositions[], int stallCount) {
    int highestCowPosition = cowPositions[cowCount - 1];
    for(int i = 0; i < stallCount; i++) {
        if(stallPositions[i] <= highestCowPosition) {
            continue;
        }
        if((stallPositions[i] - highestCowPosition) > minDist) {
            *newStallPosPtr = stallPositions[i];
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int testCaseCount;
    scanf("%i\n", &testCaseCount);
    log_out("Total Test Cases: %i\n", testCaseCount);
    
    for (int testCaseNo = 1; testCaseNo <= testCaseCount; testCaseNo++) {
        // Read input for stallCount and cowCount
        log_out("Test Case: %i\n", testCaseNo);
        int stallCount;
        int cowCount;
        scanf("%i %i\n", &stallCount, &cowCount);
        log_out("Stalls: %i\n", stallCount);
        log_out("Cows: %i\n", cowCount);

        // Read input for stallPositions and sort asc
        int stallPositions[stallCount];
        for (int i = 0; i < stallCount; i++) {
            scanf("%i\n", &stallPositions[i]);
        }
        qsortIntArray(stallPositions, stallCount);
        log_out("Stall Positions: ");
        logIntArray(stallPositions, stallCount);

        // pack cows into the left-most stalls to start
        int cowPositions[cowCount];
        for(int i = 0; i < cowCount; i++) {
            cowPositions[i] = stallPositions[i];
        }
        log_out("Cow Positions: ");
        logIntArray(cowPositions, cowCount);

        int finalResult;
        while(1) {
            // find a cow at the mininum distance that might be moved
            int minDist = 0;
            int minDistCowPosIdx = 0;
            log_out("minDist: %i\n", minDist);
            log_out("minDistCowPosIdx: %i\n", minDistCowPosIdx);
            log_out("position of cow to move: %i\n", cowPositions[minDistCowPosIdx]);

            findMinDistCow(&minDist, &minDistCowPosIdx, cowPositions, cowCount);
            log_out("minDist: %i\n", minDist);
            log_out("minDistCowPosIdx: %i\n", minDistCowPosIdx);
            log_out("position of cow to move: %i\n", cowPositions[minDistCowPosIdx]);

            // check for a suitable new stall for the cow
            int newStallPosition;
            int stallFound = checkForNewStall(&newStallPosition, minDist, cowPositions, cowCount, stallPositions, stallCount);
            if(stallFound) {
                cowPositions[minDistCowPosIdx] = newStallPosition;
                qsortIntArray(cowPositions, cowCount);
                log_out("Cow Positions: ");
                logIntArray(cowPositions, cowCount);
            } else {
                finalResult = minDist;
                break;
            }
        }

        log_out("Final Result: ");
        printf("%i\n", finalResult);


        /*
        pack cows into the left-most stalls to start
        calculate the minimum distance between any 2 cows for this configuration
        also save the index of the right cow position for this min distance pair

        figure out if there are any stalls on the right of the right-most cow that are better
            - to be better the stall must be further than the min distance from the right-most cow
        if there are no better stalls, then we're at the end solution
        if there is a better stall, move the right cow of the first min-distance pair to the better stall
        then try to seperate the rest of the min distance cows in the same manner
        */
    }


   return 0;
}