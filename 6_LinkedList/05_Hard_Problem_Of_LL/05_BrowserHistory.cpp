#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node{
public:
    Node *prev;
    string data;
    Node *next;

    // Constructor with previous and next node references
    Node(Node *prev1, int value, Node *next1)
    {
        prev = prev1;
        data = value;
        next = next1;
    }

    // Constructor with only data (for creating a new single node)
    Node(string value)
    {
        prev = nullptr;
        data = value;
        next = nullptr;
    }


};


class Browser{
    Node * currentPage;
    public:

    Browser(string &homepage){
        currentPage = new Node(homepage);
    }

    void visit(string &url){
        Node *newNode = new Node(url);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        currentPage = newNode;
    }

    string back(int steps){
        while(steps){
            if(currentPage->prev){
                currentPage = currentPage->prev;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps){
        while(steps){
            if(currentPage->next){
                currentPage = currentPage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};
// Function to convert an array to Doubly Linked List
Node *ConvertArrayToLinkedList(vector<string> &arr){
    if(arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(size_t i = 1; i< arr.size(); i++){
        Node *newNode = new Node (arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
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

int main()
{
    vector<string> urls = {"tuf.org", "google.com", "github.com"};
    Node *head = ConvertArrayToLinkedList(urls);
    print(head);
    
    Browser browser(urls[0]);

    string newurl = "instagram.com";
    browser.visit(newurl);

    string newurl2 = "facebook.com";
    browser.visit(newurl2);

    cout<< "Current page after visit: "<<browser.forward(1)<<endl;
    cout<< "Current page after go back: "<<browser.back(1)<<endl;

    
    return 0;
}
