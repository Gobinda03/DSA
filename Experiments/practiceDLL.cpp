#include <bits/stdc++.h>
using namespace std;


struct Node{
    Node*back;
    int data;
    Node*next;


    Node(Node*back1 , int data1 , Node*next1){
        back=back1;
        data = data1;
        next= next1;
    }

    Node(int data1){
        back = nullptr;
        data=data1;
        next = nullptr;
    }

};


// array to dll
Node* arrToDLL(vector<int>&arr){
    Node*head = new Node(arr[0]);

    Node*prev = head;

    for(int i = 1 ; i < arr.size() ; i++){
        Node*temp = new Node(prev,arr[i],nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}




// display
void display(Node*head){
    Node*temp = head;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


// Delete the head of the dll
Node* deleteHead(Node*head){
    
    if(head == nullptr) return nullptr;
    if (head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node*temp = head;
    head = head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;

    return head;

}


// delete the tail of the dll
Node* deleteTail(Node*head){

    if(head == nullptr) return nullptr;
    if (head->next==nullptr){
        delete head;
        return nullptr;
    }


    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node*tail = temp->back;
    tail->next=nullptr;
    temp->back=nullptr;
    delete temp;
    

    return head;
}


// delete the kth element
Node* deleteKth(Node*head,int k){
    if(head==nullptr) return nullptr;
    int cnt = 0;
    Node*temp = head;
    while(temp!=nullptr){

        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node*front = temp->next;

    if(prev==nullptr&&front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev == nullptr ){
        head = deleteHead(head);
        return head;
    }
    else if(front==nullptr){
        head = deleteTail(head);
        return head;
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return head;
    }
}




// insert at head
Node* insertHead(Node*head,int item){
    Node*newNode=new Node(item);
    if(head==nullptr) return newNode;

    newNode->next=head;
    head->back=newNode;
    head = head->back;

    return head;
}


// reverse the DLL
Node* reverseDLL(Node*head){
    Node*temp = head;

    stack<int>st;

    while(temp->next!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp->next!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}


int main() {
    vector<int>arr = {10,20,30,40,50,60,70};
    Node*head = arrToDLL(arr);
    display(head);
    
    head = deleteHead(head);
    display(head);

    head = deleteTail(head);
    display(head);

    head = deleteKth(head,3);
    display(head);

    head = insertHead(head,3);
    display(head);

    head = reverseDLL(head);
    display(head);

    return 0;
}