#include "header.h"

// 随便找一个元素，把该元素放在中间，比之小的放在前面，比之大的放在后面
void quick_sort_imp(vector<int>& nums, int start, int end) {
    if (start >= end) {
        return;
    } else if (start + 1 == end && nums[start] > nums[end]) {
        swap(nums[start], nums[end]);
        return;
    }
    // 包含start,end在内 至少有三个元素需要排序
    int k = (start + end) / 2;

    int i = start;
    int j = end;
    while (i < k && k < j) {
        if (nums[i] >= nums[k] && nums[j] <= nums[k]) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        } else if (nums[i] < nums[k]) {
            i++;
        } else if (nums[j] > nums[k]) {
            j--;
        } else {
            // 不会到这里
        }
    }

    while (i < k) {
        if (nums[i] >= nums[k]) {
            if (i + 1 == k) {
                swap(nums[i], nums[k]);
                i++;
            } else {
                swap(nums[i], nums[k - 1]);
                swap(nums[k - 1], nums[k]);
                k--;
                i++;
            }
        } else {
            i++;
        }
    }

    while (k < j) {
        if (nums[k] >= nums[j]) {
            if (j - 1 == k) {
                swap(nums[j], nums[k]);
                i++;
            } else {
                swap(nums[j], nums[k + 1]);
                swap(nums[k + 1], nums[k]);
                k++;
                j--;
            }
        } else {
            j--;
        }
    }
    quick_sort_imp(nums, start, k-1);
    quick_sort_imp(nums, k+1, end);
}

void quick_sort(vector<int>& nums) { quick_sort_imp(nums, 0, nums.size() - 1); }

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 3, 6, 3, 1, 6, 8, 0};

    print_vector(nums);

    quick_sort(nums);

    print_vector(nums);

    return 0;
}
