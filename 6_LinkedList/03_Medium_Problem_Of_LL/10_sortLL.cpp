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



// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;
    for (int j = low; j < high; j++) {        
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i+1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);         
        quickSort(arr, pi + 1, high);        
    }
}

Node* sortLL(Node*head){
    vector<int> arr;
    Node*temp = head;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp= temp->next;
    }
    quickSort(arr, 0, arr.size() - 1);
    temp = head;
    for(int i = 0 ; i<arr.size() ; i++){
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;

}

int main() {
   vector<int> arr = {10, 15, 5, 25, 20};
    int n = 2;
    Node* head1 = convertArrToLL(arr);
    Node* head2 = convertArrToLL(arr);
    
    cout << "Original:\n";
    display(head1); cout << endl;

    cout << "LL after sorting:\n";
    Node* result1 = sortLL(head1);
    display(result1); cout << endl;


    
    return 0;
}