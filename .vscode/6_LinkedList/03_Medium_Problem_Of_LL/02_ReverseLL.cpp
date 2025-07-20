#include<bits/stdc++.h>
using namespace std;


//Class for node of linked list
class Node{
    public:
    int data;
    Node*next;

    //Construction
    Node(int d){
        data=d;
        next=nullptr;
    }
};

//Converting the array to list
Node*ConvertArrToLL(vector<int>arr){

    if(arr.size()==0) return NULL;

    Node*head=new Node(arr[0]);//Declaring the array's First element as the haed of the list
    Node*mover=head;

    for(int i=1 ; i<arr.size() ; i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}


//Reverse the Linked List

Node* reverseTheList(Node*head){
    if(head==nullptr||head->next==nullptr)return head;

    Node* newhead=reverseTheList(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}

//Printing the all node of the list
void print(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int>arr={5,10,15,20};
    Node*head=ConvertArrToLL(arr);
    head = reverseTheList(head);
    print(head);
    
    return 0;
}