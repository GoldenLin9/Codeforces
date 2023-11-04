#include <stdio.h>

int main() {
    int x = 2'147'483'648;
    int y = 2*1e9;
    // printf("%d\n", x);
    while (--x > 0);
    printf("done");
}