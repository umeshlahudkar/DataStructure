#include<iostream>
#include<queue>
using namespace std;


int GetKthSmallestElement(int arr[], int n, int k) {
    if(k > n ) {return -1;}

    priority_queue<int> que;

    for(int i = 0; i < n; i++) {
        que.push(arr[i]);

        if(que.size() > k) {
            que.pop();
        }
    }

    return que.top();
}

int GetKthLargestElement(int arr[], int n, int k) {
    if(k > n ) {return -1;}

    priority_queue<int, vector<int>, greater<int>> que;

    for(int i = 0; i < n; i++) {
        que.push(arr[i]);

        if(que.size() > k) {
            que.pop();
        }
    }
    return que.top();
}

int main() {
    int arr[] = {7, 10 ,4, 3 ,20, 15};

    cout<< GetKthSmallestElement(arr, 6, 3)<<endl;
    cout<< GetKthLargestElement(arr, 6, 6)<<endl;

    return 0;
}

/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note :-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5

Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4 L=0 R=4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.
Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.
*/