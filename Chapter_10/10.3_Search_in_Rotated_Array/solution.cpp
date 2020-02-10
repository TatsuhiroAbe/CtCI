#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstddef>

using namespace std;

int helper(vector<int> &nums, int target, int left, int right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (right < left) {
        return -1;
    }

    if (nums[left] < nums[mid]) {
        if (target >= nums[left] && target < nums[mid]) {
            return helper(nums, target, left, mid - 1);
        } else {
            return helper(nums, target, mid + 1, right);
        }
    } else if (nums[mid] < nums[right]) {
        if (target > nums[mid] && target <= nums[right]) {
            return helper(nums, target, mid + 1, right);
        } else {
            return helper(nums, target, left, mid - 1);
        }
    } else if (nums[left] == nums[mid]) {
        if (nums[mid] != nums[right]) {
            return helper(nums, target, mid + 1, right);
        } else {
            int result = helper(nums, target, left, mid - 1);
            if (result == -1) {
                return helper(nums, target, mid + 1, right);
            } else {
                return result;
            }
        }
    }

    return -1;
}

int search(vector<int> &nums, int target) {
    return helper(nums, target, 0, (int)nums.size() - 1);
}

int main() {
    vector<int> nums{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout << search(nums, 5) << endl; // 8
    return 0;
}