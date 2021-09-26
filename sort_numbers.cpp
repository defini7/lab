// 2 solutions
#include <vector>

std::vector<int> solution1(std::vector<int> nums) {
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > nums[i+2] && i <= nums.size() - 2)
        std::swap(nums[i], nums[i+1]);
    return nums;
}

#include <algorithm>

std::vector<int> solution2(std::vector<int> nums) {
  sort(nums.begin(), nums.end());
  return nums;
}
