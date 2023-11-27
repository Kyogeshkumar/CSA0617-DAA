#include <stdio.h>
#define MAX_SIZE 100
int set[MAX_SIZE];
int subset[MAX_SIZE];
int n, sum;
void findSubsets(int index, int currentSum, int remainingSum) {
    if (currentSum == sum) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (currentSum > sum || remainingSum < sum - currentSum) {
        return;
    }
    for (int i = index; i < n; i++) {
        subset[index] = set[i];
        findSubsets(index + 1, currentSum + set[i], remainingSum - set[i]);
    }
}
int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += set[i];
    }
    findSubsets(0, 0, totalSum);
    return 0;
}

