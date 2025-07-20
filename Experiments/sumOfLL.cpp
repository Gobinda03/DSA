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

void PrintLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* SumOfLL(Node*head1 , Node*head2){
    Node*temp1 = head1;
    Node*temp2 = head2;

    Node*dummyNode = new Node(-1);
    Node*curr = dummyNode;
    int carry = 0;

    while(temp1!=NULL||temp2!=NULL){

        int sum = carry;
        if(temp1) sum = sum+temp1->data;
        if(temp2) sum = sum + temp2->data;

        Node*newNode = new Node(sum%10);
        carry = sum/10;

        curr->next=newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next=newNode;
    }

    return dummyNode->next;
}

int main() {
    vector<int>arr1={5,8};
    vector<int>arr2={7,5,9,9};

    Node* head1 = ConvertArrayToLinkedList(arr1);
    Node* head2 = ConvertArrayToLinkedList(arr2);

    PrintLinkedList(head1);
    PrintLinkedList(head2);


    Node*head = SumOfLL(head1,head2);
    PrintLinkedList(head);




    return 0;
}