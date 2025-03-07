ECHO is on.
#include <stdio.h>

void fixedPartitionAllocation(int blockSize[], int blockCount, int processSize[], int processCount) {
    int allocation[processCount];
    
    // Initialize all allocations to -1 (unallocated)
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }
    
    // Allocate memory using First-Fit strategy
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Reduce available memory in the block
                break;
            }
        }
    }
    
    // Display allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockCount, processCount;
    
    // Get number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blockCount);
    int blockSize[blockCount];
    
    // Get size of each block
    printf("Enter the size of each block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    
    // Get number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &processCount);
    int processSize[processCount];
    
    // Get size of each process
    printf("Enter the size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    
    // Perform memory allocation
    fixedPartitionAllocation(blockSize, blockCount, processSize, processCount);
    
    return 0;
}
