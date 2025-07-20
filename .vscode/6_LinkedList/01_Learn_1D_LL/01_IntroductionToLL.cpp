#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor for Node
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert array to linked list
Node* ConvertArrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr; // Handle empty array

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Find the length of the linked list
int LinkedListLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Check if an element is present in the linked list
bool IsElementPresent(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Print the linked list
void PrintLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {    
    vector<int> arr = {5, 10, 15, 20};

    // Convert array to linked list
    Node* head = ConvertArrayToLinkedList(arr);

    // Print the head node's data
    if (head != nullptr) {
        cout << "Head node data: " << head->data << endl;
    } else {
        cout << "Linked list is empty" << endl;
    }

    // Print the entire linked list
    cout << "Linked list: ";
    PrintLinkedList(head);

    // Find and print the length of the linked list
    cout << "Length of the linked list: " << LinkedListLength(head) << endl;

    // Check if a specific element is present in the linked list
    int valueToCheck = 5;
    cout << "Is " << valueToCheck << " present in the linked list? " 
         << (IsElementPresent(head, valueToCheck) ? "Yes" : "No") << endl;

    return 0;
}
