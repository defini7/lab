#include <stdio.h>

int solve(int nums[], int nums_sz)
{
    int count;

    for (int i = 3; i < nums_sz; i++)
        if (nums[i] + nums[i - 1] + nums[i - 2] > nums[i - 1] + nums[i - 2] + nums[i - 3])
            count++;

    return count;
}

int main()
{
    int nums_sz = 0;
    int nums[] = {};

    printf("%d\n", solve(nums, nums_sz));
}

