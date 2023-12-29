#include <iostream>
using namespace std;

int Get2ndLarget(int arr[], int n) {
    int larget = arr[0];
    int secondLargest = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] > larget) {
            secondLargest = larget;
            larget = arr[i];
        }
        else if(arr[i] < larget && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {

    int arr[] = {8,6, 2,9, 3 ,1};

    cout<< Get2ndLarget(arr, 6);

    return 0;
}
