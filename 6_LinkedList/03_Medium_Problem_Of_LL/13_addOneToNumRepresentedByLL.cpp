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

// Backtracking method

int helper(Node* temp){
    if(temp == nullptr){
        return 1;
    }

    int carry = helper(temp->next);

    temp->data+=carry;
    if(temp->data<10) return 0;
    temp->data = 0;
    return 1;
}

Node *addOne1(Node *head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next=head;
        head = newNode;
    }
    return head;
}


int main()
{
    vector<int> arr = {9, 9, 9, 9};
    int n = 2;
    Node *head1 = convertArrToLL(arr);

    cout << "Original:\n";
    display(head1);
    cout << endl;

    Node *result1 = addOne1(head1);
    cout << "Adding one to the number represented by LL" << endl;
    display(result1);

    return 0;
}