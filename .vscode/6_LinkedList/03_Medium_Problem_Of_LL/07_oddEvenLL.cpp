#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=nullptr;
    }
};

Node*convertArrToLL(vector<int>&arr){
    if(arr.size()==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node*temp = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node*newNode = new Node(arr[i]);
        temp->next=newNode;
        temp = newNode;
    }
    return head;
}

void display(Node*head){
    if(head==nullptr){
        cout<<"Blank";
    }
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


Node*oddEven(Node*head){
    if(head==nullptr) return nullptr;
    Node*temp = head;
    vector<int>arr;

    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp = head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    temp = head;
    int i = 0;
    while(temp!=nullptr){
        temp->data=arr[i];
        i++;
        temp = temp->next;
        
    }
    return head;
}


Node* OddEven(Node*head){
    Node* even = head->next;
    Node* evenHead = head->next;
    Node* odd = head;

    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        odd = odd->next;

        even->next=even->next->next;
        even = even->next;
    }

    odd->next=evenHead;
    return head;

}
int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30};

    Node* head1 = convertArrToLL(arr);
    Node* head2 = convertArrToLL(arr);

    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "oddEven (by data swap):\n";
    Node* result1 = oddEven(head1);
    display(result1); cout << endl;

    cout << "OddEven (by pointer rearrangement):\n";
    Node* result2 = OddEven(head2);
    display(result2); cout << endl;

    return 0;
}