#include <stdio.h>
#define MAX 100

void nextFit(int blocks[], int n, int processes[], int m) {
    int alloc[MAX] = {-1}, last = 0;
    for (int i = 0; i < m; i++) {
        for (int j = last, count = 0; count < n; count++, j = (j + 1) % n)
            if (blocks[j] >= processes[i]) { alloc[i] = j; blocks[j] -= processes[i]; last = j; break; }
        printf("Process %d (%d) -> %s\n", i + 1, processes[i], alloc[i] != -1 ? "Allocated" : "Not Allocated");
    }
}

int main() {
    int n, m, blocks[MAX], processes[MAX];
    printf("Enter blocks: "); scanf("%d", &n);
    printf("Sizes: "); for (int i = 0; i < n; i++) scanf("%d", &blocks[i]);
    printf("Enter processes: "); scanf("%d", &m);
    printf("Sizes: "); for (int i = 0; i < m; i++) scanf("%d", &processes[i]);
    nextFit(blocks, n, processes, m);
    return 0;
}
