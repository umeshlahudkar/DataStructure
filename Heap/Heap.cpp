#include <iostream>
using namespace std;

class MaxHeap {
    private :
        int size;
        int arr[100];
        int maxSize;

    public :
        MaxHeap() {
            size = -1;
            maxSize = 100;
        }

        void Insert(int data) {
            if(size <= maxSize) {
                size++;
                arr[size] = data;

               
                int index = size;

                while(index >= 0) {
                    int parent = (index - 1)/2;
                    if(parent < 0) {parent = 0;}

                    if(arr[parent] < arr[index]) {
                        swap(arr[parent], arr[index]);
                        index = parent;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        void Delete() {
            if(size >= 0) {

                swap(arr[0], arr[size]);
                size--;

                int index = 0;

                while( index <= size ) {
                    int largest = index;
                    int leftChild = (2* largest) + 1;
                    int rightChild = (2 * largest) + 2;

                    if(leftChild <= size && arr[leftChild] > arr[largest]) {
                        largest = leftChild;
                    }

                    if(rightChild <= size && arr[rightChild] > arr[largest]) {
                        largest = rightChild;
                    }

                    if(index != largest) {
                        swap(arr[index], arr[largest]);
                        index = largest;
                    }
                    else {
                        break;
                    }
                }
                
                
            } 
        }

        int Size() {
            return size + 1;
        }

        void Print() {
            for(int i = 0; i <= size; i++) {
                cout<< arr[i] <<" ";
            }
            cout<<endl;
        }
};

void Heapify(int arr[], int n, int i) {

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(i != largest) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {

    for(int i = ((n-1)/2); i >=0 ; i--) {
        Heapify(arr, n, i);
    }

    int size = n - 1;
    while(size >= 0) {
        swap(arr[0], arr[size]);
        Heapify(arr, size, 0);
        size--;
    }
}

int main() {
   int arr[] = {1,2,3,3,5};
   int n = 5;

   HeapSort(arr, n);

   for(int i = 0; i < n; i++) {
    cout<< arr[i] << " ";
   }

    return 0;
}