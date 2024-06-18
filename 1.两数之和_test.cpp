#include <gtest/gtest.h>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

TEST(TwoSumTest, BasicTest) {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected = {0, 1};
    std::vector<int> actual = twoSum(nums, target);
    ASSERT_EQ(actual, expected);
}

TEST(TwoSumTest, NoPairFoundTest) {
    std::vector<int> nums = {3, 2, 4};
    int target = 7;
    std::vector<int> expected = {0, 2};
    std::vector<int> actual = twoSum(nums, target);
    ASSERT_EQ(actual, expected);
}

TEST(TwoSumTest, MultiplePairsFoundTest) {
    std::vector<int> nums = {2, 2, 4, 6, 6};
    int target = 8;
    std::vector<int> expected = {0, 3};
    std::vector<int> actual = twoSum(nums, target);
    ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
