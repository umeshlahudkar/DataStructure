
#include <iostream>
using namespace std;

void SortArr(int arr[], int n) {

    int left = 0;
    int right = n-1;

    while (left <= right)
    {
        if(arr[left] < 0) {
            left++;
        }
        else if(arr[right] >= 0) {
            right--;
        }
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int nums[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = 9;

    SortArr(nums, n);

    for(int i = 0; i < n; i++) {
        cout<< nums[i] << " ";
    }

    return 0;
}

/*
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Note: Order of elements is not important here.
*/