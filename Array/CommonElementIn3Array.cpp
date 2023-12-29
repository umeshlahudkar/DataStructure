#include<iostream>
using namespace std;


void PrintCommonElementsInAllArray() {
    int arr1[] = {1, 5, 10, 20, 40, 80}; int n1 = 6;
    int n2 = 5; int arr2[] = {6, 7, 20, 80, 100};
    int n3 = 8; int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int a = 0, b =0,  c = 0;

    while(a < n1 && b < n2 && c < n3) {
        if(arr1[a] == arr2[b] && arr2[b] == arr3[c]) {
            cout<< arr1[a] << " ";
            a++;
            b++;
            c++;
        }else if(arr1[a] < arr2[b] ) {a++;}
        else if(arr2[b] < arr3[c]) {b++;}
        else {c++;}
    }
}

int main() {
    PrintCommonElementsInAllArray();
    return 0;
}

/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
*/