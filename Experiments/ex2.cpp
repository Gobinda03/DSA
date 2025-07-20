#include <iostream>
#include <vector>
using namespace std;

// Define a node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Define a LinkedList class to manage operations
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to add a new node at the end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to rearrange the linked list as per the problem statement
    void rearrangeList() {
        // Store nodes in a vector to rearrange them
        vector<Node*> nodes;
        Node* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int i = 0, j = nodes.size() - 1;
        Node* newHead = nullptr;
        Node* current = nullptr;

        while (i <= j) {
            if (!newHead) {
                newHead = nodes[i++];
                current = newHead;
            } else {
                current->next = nodes[i++];
                current = current->next;
            }

            if (i <= j) {
                current->next = nodes[j--];
                current = current->next;
            }
        }

        current->next = nullptr;
        head = newHead;
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        LinkedList list;
        int val;
        while (cin >> val && val != -1) {
            list.append(val);
        }

        list.rearrangeList();
        list.printList();
    }

    return 0;
}
