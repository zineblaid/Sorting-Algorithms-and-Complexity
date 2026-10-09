#include <stdio.h>
#include <stdlib.h>

static void swap(int *left, int *right, long long *swaps) {
    if (left == right) return;
    int temp = *left;
    *left = *right;
    *right = temp;
    (*swaps)++;
}

static int partition(int array[], int low, int high, long long *comparisons, long long *swaps) {
    int pivot = array[high];
    int smaller_index = low - 1;

    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (array[j] <= pivot) {
            smaller_index++;
            swap(&array[smaller_index], &array[j], swaps);
        }
    }

    swap(&array[smaller_index + 1], &array[high], swaps);
    return smaller_index + 1;
}

static void quick_sort(int array[], int low, int high, long long *comparisons, long long *swaps) {
    if (low < high) {
        int pivot_index = partition(array, low, high, comparisons, swaps);
        quick_sort(array, low, pivot_index - 1, comparisons, swaps);
        quick_sort(array, pivot_index + 1, high, comparisons, swaps);
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
    quick_sort(array, 0, length - 1, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) printf("%d%s", array[i], i + 1 == length ? "\\n" : " ");
    printf("Comparisons: %lld\\nSwaps: %lld\\n", comparisons, swaps);
    free(array);
    return EXIT_SUCCESS;
}
