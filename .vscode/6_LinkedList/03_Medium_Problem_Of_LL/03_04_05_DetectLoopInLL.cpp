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


//Detect the loop
bool DetectLooop(Node*head){
    unordered_map<Node*,int>mpp;
    Node*temp = head;

    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
bool DetectLoop(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr||fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return true;
    }
    return false;
}


//Length of loop present in the LL
int length(Node*slow,Node*fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;

}
int lengthOfLL(Node*head){
Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr||fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return length(slow,fast);
    }
    return 0;
}


// Starting point of loop
Node* StartingElementOfLoop(Node*head){
        unordered_map<Node*,int>mpp;
    Node*temp = head;

    while(temp!=nullptr){
        if(mpp.count(temp)!=0){
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return 0;
}

Node* StartingOfLoop(Node* head){
    Node*slow = head;
    Node*fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast= fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;  
            }
            return slow;
        }
    }
    return 0;
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
    Node* head = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(15);  
    Node* fourth = new Node(20);
    Node* fifth = new Node(25);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 


    // Check if there is a loop 
    // n the linked list
    if (DetectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    // cout<<DetectLooop(head);

    cout<<"Length of loop present in the LL : "<<lengthOfLL(head)<<endl;
    
    // Node* StartLoop = StartingElementOfLoop(head);
    Node* StartLoop = StartingOfLoop(head);
    if(StartLoop){
    cout<<"Starting element of the loop is : "<<StartLoop->data<<endl;    
    }else{
        cout<<"No loop found.";
    }
    return 0;
}