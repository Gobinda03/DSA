#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Convert array to Linked list
Node* ConvertArrToLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Inserting at head
Node* InsertAtHead(Node* head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    return head;
}

// Inserting at tail
Node* InsertAtTail(Node* head, int d) {
    Node* temp = new Node(d);
    
    if (head == nullptr) {
        return temp;
    }
    
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    return head;
}

// Inserting at Kth position
Node* InsertAtKthPosition(Node*& head, int pos, int d) {
    Node* newNode = new Node(d);
    
    if (pos == 1) {
        return InsertAtHead(head, d);
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt != pos - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    return head;
}

// ----------------------------------------------------
// Deleting functions with printing the deleted element
// ----------------------------------------------------

// Delete the head node and print deleted element
Node* DeleteHead(Node*& head) {
    if (head == nullptr) return head;
    
    Node* temp = head;
    cout << "Deleted element: " << temp->data << endl;
    
    head = head->next;
    delete temp;
    return head;
}

// Delete the last node and print deleted element
Node* DeleteTail(Node* head) {
    if (head == nullptr) return head;
    
    if (head->next == nullptr) {
        cout << "Deleted element: " << head->data << endl;
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "Deleted element: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
    
    return head;
}

// Delete the Kth node and print deleted element
Node* DeleteK(Node* head, int k) {
    if (head == nullptr) return nullptr;
    
    if (k == 1) return DeleteHead(head);
    
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;
    
    while (cnt != k && temp != nullptr) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    
    if (temp != nullptr) {
        cout << "Deleted element: " << temp->data << endl;
        prev->next = temp->next;
        delete temp;
    }
    
    return head;
}

// Delete the node with a given value and print the deleted element
Node* DeleteValue(Node* head, int val) {
    if (head == nullptr) return head;

    if (head->data == val) return DeleteHead(head);

    Node* temp = head;
    Node* prev = nullptr;
    
    while (temp != nullptr && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        cout << "Deleted element: " << temp->data << endl;
        prev->next = temp->next;
        delete temp;
    }
    
    return head;
}

// Print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 10, 12, 15};
    Node* head = ConvertArrToLL(arr);

    // Testing insertion
    head = InsertAtHead(head, 1);
    print(head);

    head = InsertAtTail(head, 20);
    print(head);

    head = InsertAtKthPosition(head, 3, 11);
    print(head);

    // Testing deletion and printing deleted elements
    head = DeleteHead(head);
    print(head);

    head = DeleteTail(head);
    print(head);

    head = DeleteK(head, 3);
    print(head);

    head = DeleteValue(head, 10);
    print(head);

    return 0;
}
