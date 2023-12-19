//  Write a menu driven program to perform following insertion 
// operations in a single linked list:0
// i.Insertion at beginning 
// ii. Insertion at end 
// iii. Insertion after a given node 
// iv. Traversing a linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at the beginning: " << value << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted at the end: " << value << endl;
    }

    void insertAfterNode(int existingValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;

        while (temp != nullptr && temp->data != existingValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << existingValue << " not found." << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted after node " << existingValue << ": " << newValue << endl;
        }
    }

    void traverse() {
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    int choice, value, existingValue;

    do {
        cout << "\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert after a Given Node\n4. Traverse\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                linkedList.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                linkedList.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter existing node value: ";
                cin >> existingValue;
                cout << "Enter new value to insert after the node: ";
                cin >> value;
                linkedList.insertAfterNode(existingValue, value);
                break;

            case 4:
                linkedList.traverse();
                break;

            case 0:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}