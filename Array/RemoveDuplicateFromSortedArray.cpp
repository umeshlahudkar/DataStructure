#include <iostream>
using namespace std;


void RemoveDuplicates(int arr[], int n) {
    int j = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1,1,2,2,2,3,4,5,5};

    RemoveDuplicates(arr, 9);

    for(int i = 0; i < 9; i++) {
        cout<< arr[i] << " ";
    }

    return 0;
}