#include <stdio.h>

int solve(int nums[], int nums_sz)
{
    int count;
    for (int i = 1; i < nums_sz; i++)
        if (nums[i - 1] < nums[i])
            count++;

    return count;
}

int main()
{
    int nums_sz = 0;
    int nums[] = {};

    printf("%d\n", solve(nums, nums_sz));
}
