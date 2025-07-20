#include<bits/stdc++.h>
using namespace std;


//Class for LL node
class Node{
    public:
    int data;
    Node* next;

    //Construction a node
    Node(int d){
        data=d;
        next=nullptr;
    }
};

//Convert array to linked list
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

//Displaying the elements of teh list
void PrintLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* findTheMiddleNode(Node*head){
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    int mid=((cnt/2)+1);
    temp=head;
    while(temp!=nullptr){
        mid=mid-1;
        if(mid==0) break;
        temp=temp->next;
    }
    return temp;
}

//Tortoise and Hare method
Node*Findmiddle(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    
    vector<int>arr={5,10,15,20,25,30};

    Node*head=ConvertArrayToLinkedList(arr);
    PrintLinkedList(head);

    Node*middleNode=findTheMiddleNode(head);
    cout<<middleNode->data<<endl;

    Node*middle=Findmiddle(head);
    cout<<middle->data;
    return 0;
}