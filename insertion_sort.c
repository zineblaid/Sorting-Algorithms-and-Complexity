#include <stdio.h>
#include <stdlib.h>

static void insertion_sort(int array[], int length, long long *comparisons, long long *moves) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparisons)++;
            if (array[j] <= key) break;
            array[j + 1] = array[j];
            (*moves)++;
            j--;
        }

        array[j + 1] = key;
        (*moves)++;
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

    long long comparisons = 0, moves = 0;
    insertion_sort(array, length, &comparisons, &moves);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) printf("%d%s", array[i], i + 1 == length ? "\\n" : " ");
    printf("Comparisons: %lld\\nMoves: %lld\\n", comparisons, moves);
    free(array);
    return EXIT_SUCCESS;
}
