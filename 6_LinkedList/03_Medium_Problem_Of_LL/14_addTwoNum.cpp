#include <bits/stdc++.h>
using namespace std;

// Nodeconstructor
struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

// Array to LL
Node *convertArrToLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

// Print LL
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "Blank";
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// Add two numbers in LL
Node *addTwoLL(Node *head1, Node *head2){
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    int carry = 0;
    int sum;

    while(temp1!=nullptr || temp2!=nullptr){
        sum = carry;

        if(temp1){
            sum = sum + temp1->data;
            temp1 = temp1->next;
        }
        if(temp2){
            sum = sum + temp2->data;
            temp2 = temp2->next;
        }
        
        Node *newNode = new Node(sum%10);
        carry = sum /10;
        curr->next = newNode;
        curr = curr->next;
    }

    if(carry){
        Node*newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {3, 5, 6, 1};
    vector<int> arr2 = {8, 1, 5, 9};
    Node *head1 = convertArrToLL(arr1);
    Node *head2 = convertArrToLL(arr2);

    cout << "Original(reverse form):\n";
    display(head1);
    cout << endl;
    display(head2);
    cout << endl;

    cout << "After adding these two LL: \n";
    Node *result1 = addTwoLL(head1, head2);
    display(result1);
    cout << endl;



    return 0;
}