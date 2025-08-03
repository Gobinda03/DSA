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
Node* reverseTheList1(Node*head){
    if(head==nullptr||head->next==nullptr)return head;

    Node* newhead=reverseTheList1(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}

Node* reverseTheList2(Node*head){
    Node *temp = head;
    Node *prev = nullptr;
    while(temp!=nullptr){
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//Printing the all node of the list
void display(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> arr = {5, 10, 15, 20, 25, 30};

    Node* head1 = ConvertArrToLL(arr);
    Node* head2 = ConvertArrToLL(arr);

    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "After reversing the LL:\n";
    Node* result1 = reverseTheList1(head1);
    display(result1); cout << endl;

    cout << "After reversing the LL :\n";
    Node* result2 = reverseTheList2(head2);
    display(result2); cout << endl;
    
    return 0;
}