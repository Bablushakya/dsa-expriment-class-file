// Write a program to find the location of a given element using Linear Search 
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not present in the array
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int elementToFind = 30;

    int result = linearSearch(myArray, size, elementToFind);

    if (result != -1) {
        cout << "Element " << elementToFind << " is present at index " << result << endl;
    } else {
        cout << "Element " << elementToFind << " is not present in the array" << endl;
    }

    return 0;
}
