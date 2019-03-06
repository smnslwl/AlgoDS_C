#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *a, int n)
{
    if (n < 2) {
        return;
    }

    for (int i = 0; i < n; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }

        int temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
    }
}

int main()
{
    printf("Selection Sort\n\n");

    int array[128];
    int length;

    printf("Enter number of items > ");
    fflush(stdout);
    scanf("%d", &length);
    fflush(stdin);

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

    selection_sort(array, length);

    printf("Sorted: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
