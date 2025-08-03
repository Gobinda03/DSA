#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=nullptr;
    }
};


// Array to LinkedList
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


// Display LinkedList
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


// Reverse nodes in K group size of LL
Node *reverseinKgroup(Node*head, int k){
    if(head == nullptr || k <= 0) return head;

    Node *temp = head;
    Node *prevNode = nullptr;

    while(temp != nullptr){
        Node *KthNode = getKthNode(temp, k);
        if(KthNode == nullptr){
            if(prevNode){
                prevNode->next = temp;
            }
            break;
        }
        Node *nextNode = KthNode->next;
        KthNode->next = nullptr;
        reverseTheList(temp);
        if(temp == head){
            head = KthNode;
        }
        else{
            prevNode->next = KthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
// Get the Kth Node
Node *getKthNode(Node *temp, int k){
    k-=1;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}
// Reverse the LL
Node* reverseTheList(Node*head){
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



int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40};

    Node* head1 = convertArrToLL(arr);
    int key = 3;

    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "Reverse nodes in k-group:\n";
    Node* result1 = reverseinKgroup(head1, key);
    display(result1); cout << endl;

    return 0;
}