#include <stdio.h>
#include <stdlib.h>

void move(int n, const char *src, const char *aux, const char *dst)
{
    if (n == 0) {
        return;
    }

    move(n - 1, src, dst, aux);
    printf("Move disk %d from %s to %s.\n", n, src, dst);
    move(n - 1, aux, src, dst);
}

int main()
{
    printf("Tower of Hanoi\n\n");

    int disks;

    printf("Enter number of disks > ");
    fflush(stdout);
    scanf("%d", &disks);
    fflush(stdin);

    if (disks < 1) {
        printf("Number of disks too low, set to 1.\n");
        disks = 1;
    }

    if (disks > 64) {
        printf("Number of disks too high, set to 64.\n");
        disks = 64;
    }

    move(disks, "left", "middle", "right");

    return 0;
}
