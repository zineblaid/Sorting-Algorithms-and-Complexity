#include <stdio.h>
#include <stdlib.h>

static void bubble_sort(int array[], int length, long long *comparisons, long long *swaps) {
    for (int i = 0; i < length - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < length - i - 1; j++) {
            (*comparisons)++;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                (*swaps)++;
                swapped = 1;
            }
        }
        if (!swapped) break;
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
    bubble_sort(array, length, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) printf("%d%s", array[i], i + 1 == length ? "\\n" : " ");
    printf("Comparisons: %lld\\nSwaps: %lld\\n", comparisons, swaps);
    free(array);
    return EXIT_SUCCESS;
}
