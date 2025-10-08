#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};

void insertatTheBeginning(int value, Node*& head){
    struct Node *newnode = new Node;
    newnode->val = value;
    newnode->next = head;
    head = newnode;
}

void insertattheend( int value, Node*& head){
    struct Node *newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    struct Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}
void insert(Node* head, int target, int value){
    Node *newnode = new Node;
    newnode->val = value;
    Node *cur = head;
    while (cur->val != target && cur->next != nullptr){
        cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;
}
void deleteNode(Node*& head, int target){
    
    if (head->next == nullptr){
        return;
    }
    Node* cur = head;
    while (cur->next->val != target && cur->next != nullptr){
        cur = cur->next;
    }
    Node* temp = cur->next;
    cur->next =cur->next->next;
    delete temp;
}
int main(){
    struct Node *head;
    struct Node *one = new Node;
    struct Node *two = new Node;
    struct Node *three = new Node;
    one->val = 11;
    two->val = 22;
    three->val = 33;
    one->next = two;
    two->next = three;
    three->next = nullptr;
    head = one;
    insertatTheBeginning(2222,head);
    insertattheend(99,head);
    insert(head,22,90);
    deleteNode(head,22);
    struct Node *cur = head;
    while (cur){
        cout<<cur->val<<endl;    
        cur = cur->next;
        
    }
}
