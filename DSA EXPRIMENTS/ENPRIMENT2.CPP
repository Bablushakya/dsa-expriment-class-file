// Write a program to delete an element from a given whose value is given 
// or whose position is given.
#include<iostream>
using namespace std;
// Function to delete an element by value
void deleteByValue(int arr[], int &size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            // Shift elements to fill the gap
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break; // Element found and deleted, exit loop
        }
    }
}
// Function to delete an element by position
void deleteByPosition(int arr[], int &size, int position) {
    // Shift elements to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
int main() {
    const int maxSize = 100; // Adjust the size as needed
    int arr[maxSize];
    int size = 0;
    // Populate the array (example)
    // ...

    // Example: Deleting element with value 42
    deleteByValue(arr, size, 42);

    // Example: Deleting element at position 2
    deleteByPosition(arr, size, 2);

    // Display the updated array
    cout << "Updated Array:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    return 0;
}
