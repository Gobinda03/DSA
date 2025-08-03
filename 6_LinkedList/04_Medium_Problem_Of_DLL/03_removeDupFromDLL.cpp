#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node{

    public:
    Node* prev;
    int data;
    Node* next;

    Node(int d){
        this->prev = nullptr;
        this->data = d;
        this->next = nullptr;
    }

    Node(Node *prev, int d, Node* next){
        this->prev = prev;
        this->data = d;
        this->next = next;
    }
};

// Convert Array to DLL
Node *convertArrayToDll(vector<int>&arr){
    if(arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(int i = 1 ; i < arr.size() ; i++){
        Node* newNode = new Node(arr[i]);
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }

    return head;

}


// Display the DLL
void display(Node* head){
    if(head == nullptr){
        cout<<"Blank";
    }

    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}




// Remove the duplicates from sorted DLL
Node *removeDuplicate(Node *head){
    if(head == nullptr || head->next == nullptr)  return head;

    Node *temp = head;
    while(temp!=nullptr){
        Node *nextNode = temp->next;
        while(nextNode!=nullptr && nextNode->data == temp->data){
            Node *dup = nextNode;
            nextNode  = nextNode->next;
            free(dup);
        }

        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
}


int main() {

    vector<int>arr = {1, 1, 1, 2, 3, 3, 4};
    Node* head = convertArrayToDll(arr);
    display(head);

    Node* result = removeDuplicate(head);
    display(result);
    return 0;
}