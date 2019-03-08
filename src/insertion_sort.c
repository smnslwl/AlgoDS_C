#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n)
{
    if (n < 2) {
        return;
    }

    for (int i = 1; i < n; i++) {
        int key = a[i];

        int j = i - 1;
        while (j >= 0 && key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{
    printf("Insertion Sort\n\n");

    int array[128];
    int length;

    printf("Enter number of items > ");
    fflush(stdout);
    scanf("%d", &length);
    fflush(stdin);

    if (length < 0) {
        length = 0;
    }

    if (length > 128) {
        length = 128;
    }

    for (int i = 0; i < length; i++) {
        printf("Item %d > ", i + 1);
        fflush(stdout);
        scanf("%d", &array[i]);
        fflush(stdin);
    }
    printf("\n");

    printf("Unsorted: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    insertion_sort(array, length);

    printf("Sorted: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
