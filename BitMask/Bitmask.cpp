
#include <iostream>
using namespace  std;

void PrintSingleNumber(int arr[], int size) {
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        result = result ^ arr[i];
    }
    cout<< "Single number : " << result << endl;
}

bool IsBitSet(int number, int bit) {
    int mask = 1 << bit;

    bool isSet = (mask & number) != 0;
    return isSet;  
}

int SetBit(int number, int bit) {
    int mask = 1 << bit;

    return mask | number;
}

int ClearBit(int number, int bit) {
    int mask = ~(1<< bit);

    return (number & mask);
}

int main() {
    int arr[] = {1,1,2,2,3,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    //PrintSingleNumber(arr, size);
    
   cout << "Set number : " << ClearBit(13, 3);


    return 0;
}
