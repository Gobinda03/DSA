#include <bits/stdc++.h>
using namespace std;


//Nodeconstructor
struct Node{
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=nullptr;
    }
};


//Array to LL
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

//Print LL
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


// method1 -> 2 time traverse
Node* delMidNode(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node*temp = head;
    int cnt=0;
    while(temp !=nullptr){
        temp=temp->next;
        cnt++;
    }
    
    cnt = cnt/2;
    int mid = 1;
    temp = head;

    while(temp!=nullptr){
        temp=temp->next;
        mid++;
        if(mid==cnt){
            break;
        }
    }

    Node* delNode = temp->next;
    temp->next=temp->next->next;
    delete delNode;
    return head;
}


// method 2 -> Hare and tortoise
Node* delMidNode2(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node*fast = head->next->next;
    Node*slow = head;


    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}


int main() {
   vector<int> arr = {5, 10, 15, 20, 25};
    int n = 2;
    Node* head1 = convertArrToLL(arr);
    Node* head2 = convertArrToLL(arr);
    
    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "Deleting the mid Node of LL:\n";
    Node* result1 = delMidNode(head1);
    display(result1); cout << endl;

    cout << "Deleting the mid Node of LL(using Hare & Toetoise method):\n";
    Node* result2 = delMidNode2(head2);
    display(result2); cout << endl;

    
    return 0;
}