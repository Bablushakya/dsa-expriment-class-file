// Write a program to find the location of a given element using Binary Search. 
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at the middle
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore the left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int elementToFind = 30;

    int result = binarySearch(myArray, 0, size - 1, elementToFind);

    if (result != -1) {
        cout << "Element " << elementToFind << " is present at index " << result << endl;
    } else {
        cout << "Element " << elementToFind << " is not present in the array" << endl;
    }

    return 0;
}
