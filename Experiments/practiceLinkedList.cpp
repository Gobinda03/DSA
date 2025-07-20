#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


// Array to linkedlist
Node*arrayToLinkedlist(vector<int>&arr){
    if(arr.size()==0)return nullptr;

    Node*head = new Node(arr[0]);
    Node*mover = head;

    for(int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


// print linkedlist
void display(Node*head){
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}


// delete head
Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
}


// delete tail
Node* deleteTail(Node* head){
    
    if (head==nullptr) return nullptr;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node*tail=head;
    while(tail->next->next!=nullptr){
    tail=tail->next;
    }
    delete tail->next;
    tail->next=nullptr;
    return head;   
    
}


// delete kth position
Node* deleteKth(Node* head , int k){
    if(head==nullptr)return head;
    if(k == 1){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node*temp = head;
    int cnt = 0;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp = temp->next;
    }

    return head;
}

// delete the kth element
Node* deleteKthele(Node* head , int k){
    if(head==nullptr)return head;
    if(head->data==k){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node*temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp = temp->next;
    }

    return head;
}





// insert at head
Node* insertHead(Node*head, int ele){
    Node*temp = new Node(ele);

    temp->next=head;
    return temp;
}


// insert at tail
Node* insertatTail(Node*head , int ele){
    Node* newNode = new Node(ele);
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next=newNode;
    newNode->next=nullptr;

    return head;
}


// insert at kth element
Node* insertatkth(Node*head , int element,int k){
    Node*newNode = new Node(element);
    Node*temp = head;

    if(head==nullptr){
        if(k==1) return newNode;
    }
    if(k==1){
        newNode->next=head;
        return newNode;
    }

    while((k-1)!=1 && temp->next!=nullptr){
        temp = temp->next;
        k--;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    return head;


}



int main() {
    vector<int>arr = {10,15,20,25,30};
    Node*head = arrayToLinkedlist(arr);
    if (head != nullptr) {
        cout << "Head node data: " << head->data << endl;
    } else {
        cout << "Linked list is empty" << endl;
    }
    display(head);
    // head = deleteHead(head);
    display(head);
    // head=deleteTail(head);
    display(head);
    head = deleteKth(head,10);
    display(head);
    head = deleteKthele(head,40);
    display(head);
    head = insertHead(head,5);
    display(head);
    head = insertatTail(head,50);
    display(head);
    head = insertatkth(head,100,1);
    display(head);

    return 0;
}