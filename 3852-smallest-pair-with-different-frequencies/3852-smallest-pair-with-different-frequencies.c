#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* minDistinctFreqPair(int* nums, int numsSize, int* returnSize) {
    
    // Allocate result array
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    if (numsSize < 2) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Arrays to store distinct values and their frequencies
    int* values = (int*)malloc(numsSize * sizeof(int));
    int* freq   = (int*)malloc(numsSize * sizeof(int));

    int k = 0;  // count of distinct elements

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            values[k] = nums[i];
            freq[k] = 1;
            k++;
        } else {
            freq[k - 1]++;
        }
    }

    // Find required pair
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (freq[i] != freq[j]) {
                result[0] = values[i];
                result[1] = values[j];
                free(values);
                free(freq);
                return result;
            }
        }
    }

    // If no valid pair found
    result[0] = -1;
    result[1] = -1;

    free(values);
    free(freq);
    return result;
}