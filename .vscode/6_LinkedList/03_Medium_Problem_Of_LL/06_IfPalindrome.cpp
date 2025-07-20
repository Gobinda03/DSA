#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

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


bool ifPalindrome(Node*head){
    stack<int>st;
    Node*temp = head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp !=nullptr){
        if(temp->data!=st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main() {
    vector<int>arr={1,2,3,2,1};

    Node*head=ConvertArrayToLinkedList(arr);
    PrintLinkedList(head);

    if(ifPalindrome(head)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }

    return 0;
}