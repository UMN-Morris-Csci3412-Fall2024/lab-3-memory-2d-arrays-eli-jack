#include "mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

bool needsSorting(int rangeSize) {
    return rangeSize >= 2;
}

void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
    const int rangeSize = endIndex - startIndex;
    int *destination = (int *)malloc(rangeSize * sizeof(int));
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    while (firstIndex < midPoint && secondIndex < endIndex) {
        if (values[firstIndex] < values[secondIndex]) {
            destination[copyIndex] = values[firstIndex++];
        } else {
            destination[copyIndex] = values[secondIndex++];
        }
        copyIndex++;
    }
    while (firstIndex < midPoint) {
        destination[copyIndex++] = values[firstIndex++];
    }
        while (secondIndex < endIndex) {
        destination[copyIndex++] = values[secondIndex++];
    }
    for (int i = 0; i < rangeSize; i++) {
        values[i + startIndex] = destination[i];
    }
    free(destination);
}

void mergesortRange(int values[], int startIndex, int endIndex) {
    int rangeSize = endIndex - startIndex;
    if (needsSorting(rangeSize)) {
        int midpoint = (startIndex + endIndex) / 2;
        mergesortRange(values, startIndex, midpoint);
        mergesortRange(values, midpoint, endIndex);
        mergeRanges(values, startIndex, midpoint, endIndex);
    }
}

void mergesort(int size, int values[]) {
    mergesortRange(values, 0, size);
}
