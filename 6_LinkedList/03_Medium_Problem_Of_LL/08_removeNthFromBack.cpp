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

//method1
Node* rmvNthFromBack1(Node*head, int n){
    if(head==nullptr) return nullptr;
    Node* temp = head;
    int cnt = 0;
    
    //Size of LL
    while(temp!=nullptr){
        cnt++;
        temp = temp->next;
    }
    temp = head;
    if(n > cnt) return 0;
    else if(cnt==n){
        Node* newHead = head->next;
        free(head);
        return  newHead;
    }

    int res = cnt - n;
    while(res!=1){
        temp = temp->next;
        res--;
    }
    Node*dltNode = temp->next;
    temp->next=temp->next->next;
    free(dltNode);
    return head;
}


// method2
Node* rmvNthFromBack2(Node* head, int n){

    if(head==nullptr) return nullptr;

    Node* fast = head;
    Node* slow = head;

    for(int i = 0 ; i < n ; i++){
        fast = fast->next;
    }
    if(fast==nullptr){
        Node* newHead = head->next;
        free(head);
        return  newHead;
    }

    while(fast->next!=nullptr){
        fast= fast->next;
        slow= slow->next;
    }
    Node* delNode = slow->next;
    slow->next=slow->next->next;
    free(delNode);
    return head;
}
int main() {
   vector<int> arr = {5, 10, 15, 20, 25, 30};
    int n = 2;
    Node* head = convertArrToLL(arr);
    Node* head2 = convertArrToLL(arr);
    
    cout << "Original:\n";
    display(head); cout << endl;

    cout << "Deleting the" <<n<<"th node from back of LL:\n";
    Node* result = rmvNthFromBack1(head, n);
    display(result); cout << endl;

    cout << "Deleting the" <<n<<"th node from back of LL:\n";
    Node* result2 = rmvNthFromBack2(head2, n);
    display(result2); cout << endl;



    return 0;
}