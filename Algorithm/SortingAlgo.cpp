#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size) {
    for(int i = 0; i <= size-2; i++) {
        int min = i;
        for(int j =  i + 1; j <= size-1; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
}

void Bubble_Sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < size - 1 -i; j++) {
            if(arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }

        if(!swapped) {break;}
    }
}

void InsertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1] )
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

void Merge(int arr[], int low, int mid, int high) {
    int temp[low+high+1];

    int left = low;
    int right = mid+1;

    int index = -1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            index++;
            temp[index] = arr[left];
            left++;
        }
        else {
            index++;
            temp[index] = arr[right];
            right++;
        }
    }

    while (left <= mid)
    {
        index++;
        temp[index] = arr[left];
        left++;
    }

    while(right <= high) {
        index++;
        temp[index] = arr[right];
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    
}

void MergeSort(int arr[], int low, int high) {
    if(low == high) {
        return;
    }

    int mid = (low + high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

int Partition(int arr[], int low, int high) {
    int start = low;
    int end = high;
    int pivot = 0;

    while(start <= end) {
       while(arr[start] <= arr[pivot]) {
            start++;
       }

       while (arr[end] > arr[pivot])
       {
            end--;
       }
       
       if(start < end) {
        swap(arr[start], arr[end]);
       }
    }

    swap(arr[pivot], arr[end]);
    return end;
}

void QuickSort(int arr[], int low, int high) {
    if(low >= high) {
        return;
    }
    //if(low < high) {
        int index = Partition(arr, low, high);
        QuickSort(arr, low, index-1);
        QuickSort(arr, index + 1, high);
    //}
}

int main() {
    int arr[] = {5, 1, 8, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr, 0, size-1);

    for(int i = 0; i < size; i++) {
        cout<< arr[i] << " ";
    }
}

