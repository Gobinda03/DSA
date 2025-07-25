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


Node* sort_1(Node *head){
    if(head==nullptr || head->next==nullptr) return head;
    Node*temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while(temp){
        if(temp->data==0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;
    while(temp){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp = temp->next;
    }

    return head;
}


int main()
{
    vector<int> arr = {0, 1, 0, 2, 0, 1, 1, 2};
    int n = 2;
    Node *head1 = convertArrToLL(arr);
    Node *head2 = convertArrToLL(arr);

    cout << "Original:\n";
    display(head1);
    cout << endl;

    Node* result1 = sort_1(head1);
    cout<<"Sort LL of 0's, 1's and 2's"<<endl;
    display(result1);

    return 0;
}