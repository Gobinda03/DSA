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

// QuickSort-based LL sorting (Method 1)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
Node *sortLL(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    quickSort(arr, 0, arr.size() - 1);
    temp = head;
    for (int i = 0; i < arr.size(); i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

// MergeSort-based LL sorting (Method 2)
Node *findMid(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *marge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    temp->next = (list1 != nullptr) ? list1 : list2;
    return dummyNode->next;
}
Node *sortLL2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *mid = findMid(head);
    Node *leftHead = head;
    Node *rightHead = mid->next;
    mid->next = nullptr;

    leftHead = sortLL2(leftHead);
    rightHead = sortLL2(rightHead);
    return marge(leftHead, rightHead);
}

int main()
{
    vector<int> arr = {10, 15, 5, 25, 20};
    int n = 2;
    Node *head1 = convertArrToLL(arr);
    Node *head2 = convertArrToLL(arr);

    cout << "Original:\n";
    display(head1);
    cout << endl;

    cout << "LL after sorting:\n";
    Node *result1 = sortLL(head1);
    display(result1);
    cout << endl;

    cout << "LL after margesort:\n";
    Node *result2 = sortLL2(head2);
    display(result2);
    cout << endl;

    return 0;
}