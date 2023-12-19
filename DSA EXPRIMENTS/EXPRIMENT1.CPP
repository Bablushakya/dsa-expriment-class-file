// Write a program to insert a new element at the end as well as at a given position in an array.
#include<iostream>
using namespace std;

// Function to insert element at the end of the array
void insertAtEnd(int arr[], int &size, int element) {
    arr[size] = element;
    size++;
}

// Function to insert element at a specific position in the array
void insertAtPosition(int arr[], int &size, int element, int position) {
    // Shift elements to create space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element at the specified position
    arr[position] = element;
    size++;
}

int main() {
    const int maxSize = 100; // Adjust the size as needed
    int arr[maxSize];
    int size = 0;

    // Example: Inserting 42 at the end
    insertAtEnd(arr, size, 42);

    // Example: Inserting 99 at position 2
    insertAtPosition(arr, size, 99, 2);

    // Display the updated array
    cout << "Updated Array:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }

    return 0;
}
