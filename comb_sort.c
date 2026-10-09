#include <stdio.h>
#include <stdlib.h>

static void comb_sort(int array[], int length, long long *comparisons, long long *swaps) {
    int gap = length;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = 0;
        for (int i = 0; i + gap < length; i++) {
            (*comparisons)++;
            if (array[i] > array[i + gap]) {
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                (*swaps)++;
                swapped = 1;
            }
        }
    }
}

int main(void) {
    int length;
    printf("Enter the number of elements: ");
    if (scanf("%d", &length) != 1 || length <= 0) {
        fprintf(stderr, "Please enter a positive array size.\\n");
        return EXIT_FAILURE;
    }

    int *array = malloc((size_t)length * sizeof(*array));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers: ", length);
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input.\\n");
            free(array);
            return EXIT_FAILURE;
        }
    }

    long long comparisons = 0, swaps = 0;
    comb_sort(array, length, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) printf("%d%s", array[i], i + 1 == length ? "\\n" : " ");
    printf("Comparisons: %lld\\nSwaps: %lld\\n", comparisons, swaps);
    free(array);
    return EXIT_SUCCESS;
}
