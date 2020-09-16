/**
 * @file search_insert_position.h
 * @author myliuda@sina.com
 * @version 0.0.0
 * @date 2020-02-05
 *
 * @brief
 * Given a sorted array and a target value, return the index if the
 * target is found. If not, return the index where it would be if it were
 * inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class SearchInsertPosition {
public:
    int searchInsert_Review(vector<int> &nums, int target) {
        for (uint32_t i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }

    int searchInsert(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (!(nums[i] < target)) return i;
        return nums.size();
    }
};
