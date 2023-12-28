#include <iostream>
using namespace std;

#include <map>
#include <unordered_map>



int main() {
   int arr[] = {1,1,4,4,2,2,8,5, 1};
   int size = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> hasMap;
   for(int i = 0; i < size; i++) {
        hasMap[arr[i]]++;
   }

   unordered_map<int, int>::iterator it;

   for(it = hasMap.begin(); it != hasMap.end(); it++) {
    cout<< it->first << " -> " << it->second << endl;
   }

}