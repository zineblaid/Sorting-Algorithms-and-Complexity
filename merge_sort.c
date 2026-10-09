#include <stdio.h>
#include <stdlib.h>

static void merge(int array[], int temp[], int left, int middle, int right,
                  long long *comparisons, long long *moves) {
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {
        (*comparisons)++;
        if (array[i] <= array[j]) temp[k++] = array[i++];
        else temp[k++] = array[j++];
        (*moves)++;
    }

    while (i <= middle) {
        temp[k++] = array[i++];
        (*moves)++;
    }
    while (j <= right) {
        temp[k++] = array[j++];
        (*moves)++;
    }

    for (i = left; i <= right; i++) array[i] = temp[i];
}

static void merge_sort(int array[], int temp[], int left, int right,
                       long long *comparisons, long long *moves) {
    if (left >= right) return;

    int middle = left + (right - left) / 2;
    merge_sort(array, temp, left, middle, comparisons, moves);
    merge_sort(array, temp, middle + 1, right, comparisons, moves);
    merge(array, temp, left, middle, right, comparisons, moves);
}

int main(void) {
    int length;
    printf("Enter the number of elements: ");
    if (scanf("%d", &length) != 1 || length <= 0) {
        fprintf(stderr, "Please enter a positive array size.\\n");
        return EXIT_FAILURE;
    }

    int *array = malloc((size_t)length * sizeof(*array));
    int *temp = malloc((size_t)length * sizeof(*temp));
    if (array == NULL || temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\\n");
        free(array);
        free(temp);
        return EXIT_FAILURE;
    }

    printf("Enter %d integers: ", length);
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input.\\n");
            free(array);
            free(temp);
            return EXIT_FAILURE;
        }
    }

    long long comparisons = 0, moves = 0;
    merge_sort(array, temp, 0, length - 1, &comparisons, &moves);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) printf("%d%s", array[i], i + 1 == length ? "\\n" : " ");
    printf("Comparisons: %lld\\nMoves: %lld\\n", comparisons, moves);
    free(array);
    free(temp);
    return EXIT_SUCCESS;
}
