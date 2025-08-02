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




// pairs with given sum in DLL

Node *findTail(Node* head){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> pairSum(Node *head, int sum){
    vector<pair<int, int>>ans;
    if(head == nullptr) return ans;

    Node *left = head;
    Node *right = findTail(head);

    while(left->data < right->data){
        if(left->data+right->data == sum){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(left->data+right->data > sum){
            right = right->prev;
        }
        else{
            left = left->next;
        }
    }
    return ans;
}


int main() {

    vector<int>arr = {1, 2, 3, 4, 9};
    Node* head = convertArrayToDll(arr);
    display(head);

    int sum = 5;
    vector<pair<int, int>>result = pairSum(head, sum);  
    for(auto it: result){
        cout<<"["<<it.first<<", "<<it.second<<"]";
    }  
    return 0;
}