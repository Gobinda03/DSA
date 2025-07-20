#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // Constructor with previous and next node references
    Node(Node *prev1, int value, Node *next1)
    {
        prev = prev1;
        data = value;
        next = next1;
    }

    // Constructor with only data (for creating a new single node)
    Node(int value)
    {
        prev = nullptr;
        data = value;
        next = nullptr;
    }
};

// Function to convert an array to Doubly Linked List
Node *ConvertArrayToLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr; // Handle empty array case

    Node *head = new Node(arr[0]); // First node
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(prev, arr[i], nullptr);
        prev->next = temp;
        prev = temp;
    }

    return head;
}


//Deletion operation
// Function to delete the head node of the list
Node *DeleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr; // Handle empty list case

    Node *temp = head;

    if (head->next == nullptr)
    { // Only one element in the list
        cout<<"Deleted element :"<<temp->data<<endl;
        delete temp;
        return nullptr;
    }

    head = head->next; // Move the head to the next node
    head->prev = nullptr;
    cout<<"Deleted element :"<<temp->data<<endl;
    delete temp; // Free the old head

    return head;
}

// Function to delete the tail node of the list
Node *DeleteTail(Node *head)
{
    Node *temp = head;

    if (head == nullptr)
        return nullptr; // Handle empty list case

    if (head->next == nullptr)
    { // Only one element in the list
        cout<<"Deleted element :"<<temp->data<<endl;
        delete head;
        return nullptr;
    }


    while (temp->next != nullptr)
    { // Traverse to the end of the list
        temp = temp->next;
    }

    Node *tail = temp->prev; // Get the second last node
    tail->next = nullptr;    // Set its next to nullptr (remove the last node)
    cout<<"Deleted element :"<<temp->data<<endl;
    delete temp;             // Free the old tail

    return head;
}

// Function to delete the Kth element of the list
Node *DeleteKthElement(Node *head, int position)
{
    if (head == nullptr)
        return nullptr; // Handle empty list

    Node *temp = head;
    int cnt = 0;
    // Traverse the list to get the Kth element
    while (temp != nullptr)
    {
        cnt++;
        if(cnt==position) break;
        temp=temp->next;
    }
    Node*back=temp->prev;//Pointing the node before Kth node
    Node*front=temp->next;//Pointing the node after Kth node
    
    //single node
    if(back==NULL&&front==NULL){
        return nullptr;
        cout<<"Deleted element "<<temp->data<<endl;//Handle the Single element node
        delete temp;//Memory free
    }

    //Head
    else if(back==NULL){
        return DeleteHead(head);//Handling the first element or head
    }

    //Tail
    else if(front==NULL){
        return DeleteTail(head);//Handling the last element or tail
    }

    else{
        back->next=front;
        front->prev=back;

        temp->next=nullptr;
        temp->prev=nullptr;

        cout<<"Deleted element : "<<temp->data<<endl;
        delete temp;//Memory free
        return head;
    }


}

//Function to delete the Specific element
void deleteNode(Node* temp){
    Node*back=temp->prev;
    Node*front=temp->next;

    if(front==NULL){
        back->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return;
    }
    back->next=front;
    front->prev=back;

    temp->prev=temp->next=nullptr;
    delete temp;
}



//Insertion operation

//Functuin to insert at First position
Node*InsertAtHead(Node*head,int value){
    Node*temp=new Node(value);//Creating the new node with given element
    if(head==nullptr)return temp;//handle the empty list case...

    temp->next=head;
    head->prev=temp;
    head=temp;//Shifting the head position
    return head;
}


// Function to print the elements of the list
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//print the length of the list
void LengthOfTheDLL(Node*head){
    Node*temp=head;
    int cnt=0;
    do{
        cnt++;
        temp=temp->next;
    }
    while(temp!=NULL);
    cout<<"The length of the linked is : "<<cnt<<endl;
}

int main()
{
    vector<int> arr = {5, 10, 15, 20, 25, 30};

    Node *head = ConvertArrayToLinkedList(arr); // Convert array to doubly linked list
    print(head);                                // Print the list
    LengthOfTheDLL(head);//Print the lenght of the linked list


    head = DeleteHead(head); // Delete the head node
    print(head);             // Print the updated list
    LengthOfTheDLL(head);//Print the lenght of the linked list


    head = DeleteTail(head); // Delete the tail node
    print(head);             // Print the updated list
    LengthOfTheDLL(head);//Print the lenght of the linked list


    head = DeleteKthElement(head, 3);//Delete the Kth Element
    print(head);//Print the updated list
    LengthOfTheDLL(head);//Print the lenght of the linked list


    deleteNode(head->next);//Delete the specify node
    print(head);//printh the updated list
    LengthOfTheDLL(head);//Print the lenght of the linked list

    
    head = InsertAtHead(head,5);//Insert the element before head postion
    print(head);//Print tehe updated list
    LengthOfTheDLL(head);//Print the lenght of the linked list

    return 0;
}
