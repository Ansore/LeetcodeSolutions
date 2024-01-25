#include <stdio.h>
#include <stdlib.h>
int giveGem(int *gem, int gemSize, int **operations, int operationsSize,
            int *operationsColSize) {
  int max = 0, min;
  for (int i = 0; i < operationsSize; i++) {
    gem[operations[i][1]] += gem[operations[i][0]] / 2;
    gem[operations[i][0]] -= gem[operations[i][0]] / 2;
  }
  max = gem[0];
  min = gem[0];
  for (int i = 0; i < gemSize; i++) {
    if (max < gem[i]) {
      max = gem[i];
    }
    if (min > gem[i]) {
      min = gem[i];
    }
  }
  return max - min;
}

int main(int argc, char *argv[]) {
  int operationsColSize = 2;
  int gem[3] = {3, 1, 2};
  // int operations[3][2] = {{0, 2}, {2, 1}, {2, 0}};
    int *operations[3]; // 将 operations 声明为指向指针的指针
  for (int i = 0; i < 3; i++) {
    operations[i] = malloc(2 * sizeof(int));
  }
  operations[0][0] = 0; operations[0][1] = 2;
  operations[1][0] = 2; operations[1][1] = 1;
  operations[2][0] = 2; operations[2][1] = 0;
  printf("%d\n", giveGem(gem, 3, operations, 3, &operationsColSize));
  return 0;
}
