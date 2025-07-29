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

void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
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

// Method1: Hasing
Node *intersectPoint1(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr || head1 == head2)
        return head1;
    unordered_set<Node *> st;
    Node *temp1 = head1;
    while (temp1 != nullptr)
    {
        st.insert(temp1);
        temp1 = temp1->next;
    }

    Node *temp2 = head2;
    while (temp2 != nullptr)
    {
        if (st.find(temp2) != st.end())
            return temp2;

        temp2 = temp2->next;
    }

    return nullptr;
}


// Method2: Travelser
Node* intersectPoint2(Node* head1, Node* head2){
    if (head1 == nullptr || head2 == nullptr || head1 == head2)
        return head1;

    Node* temp2 = head2;

    while(temp2!=nullptr){
        Node* temp1 = head1;
        while(temp1!=nullptr){
            if(temp1==temp2) 
                return temp1;
            else
                temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    return nullptr;

}



Node* intersectPoint3(Node* head1, Node* head2){
    if (head1 == nullptr || head2 == nullptr || head1 == head2)
        return head1;
    
    Node *temp1 = head1;
    Node* temp2 = head2;

    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2)return temp1;
        else if(temp1==nullptr) temp1=head2;
        else if(temp2==nullptr) temp2=head1;   
    }
    return temp1;
}
int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node *head1 = head;
    head = head->next->next->next;
    Node *headSec = NULL;
    insertNode(headSec, 3);
    Node *head2 = headSec;
    headSec->next = head;

    cout << "List1: ";
    display(head1);
    cout << "\nList2: ";
    display(head2);

    Node *result1 = intersectPoint1(head1, head2);
    cout << "\nIntersecting point of those given LL is: " << endl;
    cout << result1 <<endl<< result1->data << endl;

    Node *result2 = intersectPoint2(head1, head2);
    cout << "\nIntersecting point of those given LL is: " << endl;
    cout <<result2 <<endl<< result2->data << endl;

    Node *result3 = intersectPoint3(head1, head2);
    cout << "\nIntersecting point of those given LL is: " << endl;
    cout <<result3 <<endl<< result3->data << endl;

    return 0;
}