#include <iostream>
using namespace std;


int BinarySearch(int arr[], int size, int number) {
    
    int low = 0, high = size-1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low)/2;

        if(arr[mid] == number) {return mid;}
        else if(arr[mid] < number) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int BinarySearchByRecursive(int arr[], int low, int high, int number) {
    if(low > high) {return -1;}

    int mid = low + (high - low)/2;

    if(arr[mid] == number) {return mid;}
    else if(arr[mid] < number) {
        return BinarySearchByRecursive(arr, mid + 1, high, number);
    }
    else {
        return BinarySearchByRecursive(arr, low, mid - 1, number);
    }
}

int LowerBound(int arr[], int size, int number) {
    int low = 0, high = size-1, index = size;

    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low)/2;

        if(arr[mid] >= number) {
            index = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return index;
}

int UpperBound(int arr[], int size, int number) {
    int low = 0, high = size-1, index = size;

    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low)/2;

        if(arr[mid] > number) {
            index = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return index;
}

int FloorValue(int arr[], int size, int number) {
    int low = 0;
    int high = size - 1;

    int ans = -1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if(arr[mid] <= number) {
            ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int CeilValue(int arr[], int size, int number) {
    int low = 0;
    int high = size - 1;

    int ans = -1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if(arr[mid] >= number) {
            ans = arr[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1,2,3,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< "Index : "<< CeilValue(arr, size,  5) <<endl;


   return 0;
}