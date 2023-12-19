// Write a menu driven program to perform following deletion operations 
// in a single linked list: 
// i. Deletion at beginning 
// ii. Deletion at end 
// iii. Deletion after a given node
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
        cout << "Inserted: " << value << endl;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted at the beginning." << endl;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Deleted at the end." << endl;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Deleted at the end." << endl;
        }
    }

    void deleteAfterNode(int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Node with value " << value << " not found or it is the last node." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Deleted after node " << value << "." << endl;
        }
    }

    void display() {
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
    int choice, value, nodeValue;

    do {
        cout << "\nMenu:\n1. Insert at End\n2. Delete at Beginning\n3. Delete at End\n4. Delete after a Given Node\n5. Display\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                linkedList.insertAtEnd(value);
                break;

            case 2:
                linkedList.deleteAtBeginning();
                break;

            case 3:
                linkedList.deleteAtEnd();
                break;

            case 4:
                cout << "Enter node value after which deletion should occur: ";
                cin >> nodeValue;
                linkedList.deleteAfterNode(nodeValue);
                break;

            case 5:
                linkedList.display();
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