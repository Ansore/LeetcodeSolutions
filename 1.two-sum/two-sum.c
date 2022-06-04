#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	/*int result[2] = {0, 0};*/
	int *result = NULL;
	result = (int*) malloc(2 * sizeof(int));

	for(int i = 0; i < numsSize; i ++) {
		if(nums[i] <= target) {
			result[0] = i;
			int temp = target - nums[i];
			for(int j = 0; j < numsSize; j ++) {
				if(temp == nums[j]) {
					result[1] = j;
					return result;
				}
			}
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	int nums[4] = {2, 7, 11, 15};
	int target = 9;

	int* r = twoSum(nums, 4, target, NULL);

	for(int i = 0; i < 2; i ++) {
		printf("%d", r[i]);
	}
	
	return 0;
}
