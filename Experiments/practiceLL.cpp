#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node*next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};


//Converting the Array to LL
Node*arrToLL(vector<int>&arr){
    if (arr.size()==0) return nullptr;

    Node*head = new Node(arr[0]);
    Node*temp = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node*newNode = new Node(arr[i]);
        temp->next=newNode;
        temp = temp->next;
    }

    return head;

}


//Displaing LL
void display(Node*head){    
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


//Middle of the LL
Node*MiddleEl(Node*head){
    int n = 0;
    Node*temp = head;
    while (temp!=nullptr){
        n++;
        temp=temp->next;
    }

    int middlepos = (n/2)+1;
    temp = head;
    while(temp!=nullptr){
        middlepos=middlepos-1;;
        if(middlepos==0) break;
        temp=temp->next;
    }
    return temp;
}

Node*MiddleEle(Node*head){
    Node*slow = head;
    Node*fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


//reverse the LL
bool hasLoop(Node*head){
    Node*slow = head;
    Node*fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main() {
    vector<int>arr = {5,10,15,20,25,30};
    Node*head = arrToLL(arr);
    display(head);

    // Node*middle = MiddleEl(head);
    // cout<<middle->data<<"\n";

    // Node*mid = MiddleEle(head);
    // cout<<mid->data;

    cout<<hasLoop(head);


    return 0;
}