#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;
    Node *child;

    Node(){
        this->data = 0;
        this->next = nullptr;
        this->child = nullptr;
    }
    Node(int d){
        this->data=d;
        this->next=nullptr;
        this->child = nullptr;
    }
    Node(int d, Node *nextNode, Node *childNode){
        this->data=d;
        this->next= nextNode;
        this->child = childNode;
    }
};


// Array to LinkedList
Node*convertArrToLL(vector<int>&arr){
    if(arr.size()==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node*temp = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node*newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}


void printOriginalLinkedList(Node* head, int depth = 0) {
    while (head != nullptr) {
        for (int i = 0; i < depth; ++i) {
            cout << "| ";
        }

        // Print current node data
        cout << head->data;

        // If there is a child, print recursively with arrow
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        if (head->next) {
            cout << endl;
        }

        head = head->next;
    }
}



// Display LinkedList
void display(Node*head){
    if(head==nullptr){
        cout<<"Blank";
    }
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->child;
    }

}


// Flattening the LL 
/*      TC = O(N*M)*2 + O(N*MlogN*M)
        SC = O(N*M)*2             */
Node *flattenLL(Node*head){
    vector<int>arr;
    Node *temp = head;

    while(temp!= nullptr){
        Node *temp2 = temp;
        while(temp2 != nullptr){
            arr.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    head = convertArrToLL(arr);
    return head;
}



Node *margeTwoList(Node *list1, Node *list2){
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }

    if(list1) res->child = list1;
    else res->child = list2;

    if(dummyNode->child) dummyNode->child->next = nullptr;
    return dummyNode->child;
}
Node *flattenLL2(Node*head){
    if(head == nullptr || head->next == nullptr) return head;

    Node * margeHead = flattenLL2(head->next);
    head = margeTwoList(head, margeHead);
    return head;
}

int main() {
    Node *head = new Node(2);

    head->next = new Node(1);
    head->next->child = new Node(6);
    head->next->child->child = new Node(8);

    head->next->next = new Node(4);
    head->next->next->child = new Node(3);

    head->next->next->next = new Node(5);
    head->next->next->next->child = new Node(7);
    head->next->next->next->child->child = new Node(9);


    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // cout << "After flattening the LL:\n";
    // Node* result1 = flattenLL(head);
    // display(result1);
    // cout << endl;


    cout << "After flattening the LL:\n";
    Node* result2 = flattenLL2(head);
    display(result2);
    cout << endl;

    return 0;
}