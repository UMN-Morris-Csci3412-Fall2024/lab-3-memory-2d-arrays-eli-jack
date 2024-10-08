#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

// Function to merge multiple arrays into a single sorted array with unique elements
int* array_merge(int num_arrays, int* sizes, int** values) {
    int totalElements = 0;

    // Calculate the total number of elements across all arrays
    for (int i = 0; i < num_arrays; i++) {
        totalElements += sizes[i];
    }

    // If there are no elements, return an array containing only 0
    if (totalElements == 0) {
        int *zeroArray = (int *)malloc(sizeof(int));
        zeroArray[0] = 0;
        return zeroArray;
    }

    // Allocate memory for the merged array
    int *mergedArray = (int *)malloc(totalElements * sizeof(int));
    int index = 0;

    // Copy all elements from the input arrays into the merged array
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            mergedArray[index++] = values[i][j];
        }
    }

    // Sort the merged array
    mergesort(totalElements, mergedArray);

    // Remove duplicates from the sorted array
    int uniqueValues = 1;
    for (int i = 1; i < totalElements; i++) {
        if (mergedArray[i] != mergedArray[i - 1]) {
            mergedArray[uniqueValues++] = mergedArray[i];
        }
    }

    // Allocate memory for the result array, which includes the count of unique elements
    int *results = (int *)malloc((uniqueValues + 1) * sizeof(int));
    results[0] = uniqueValues;

    // Copy the unique elements into the result array
    for (int i = 0; i < uniqueValues; i++) {
        results[i + 1] = mergedArray[i];
    }

    // Free the memory allocated for the merged array
    free(mergedArray);

    // Return the result array
    return results;
}
