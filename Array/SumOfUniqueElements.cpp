#include <iostream>
using namespace std;

#include <unordered_map>

int GetSumOfUniqueElement(int arr[], int n) {

    unordered_map<int, int> map ;

    for(int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    int count = 0;
    unordered_map<int, int>::iterator it;
    for(it = map.begin(); it != map.end(); it++) {
        if(it->second <= 1) {
            count += it->first;
        }
    }

    return count;
}



int main() {
    int arr[] = {1,2,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< GetSumOfUniqueElement(arr, size);

    return 0;
}

/*
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

Return the sum of all the unique elements of nums.

 

Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
Example 3:

Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/