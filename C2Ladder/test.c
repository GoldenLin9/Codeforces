#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count(int n) {
    if (n == 1) return;
    printf("%d\n", n);
    count(n-1);
}

int main() {
    count(5);
}