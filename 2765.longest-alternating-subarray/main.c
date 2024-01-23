#include <stdio.h>

int alternatingSubarray(int *nums, int numsSize) {
  int ret = -1, tmp = 1, flag = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] - nums[i - 1] == flag) {
      tmp += 1;
      flag = -flag;
      if (i == numsSize - 1) {
        return ret > tmp ? ret : tmp;
      }
    } else {
      if (tmp > ret && tmp != 1) {
        ret = tmp;
      }
      if (tmp != 1) {
        i--;
        flag = 1;
        tmp = 1;
      }
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int nums[] = {21, 9, 5};
  printf("%d\n", alternatingSubarray(nums, 3));
  return 0;
}
