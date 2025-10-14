#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
};
class ListNode{
    private:
        Node *head, *cur;
        int n;
    public:
        ListNode(){
            head = nullptr;
            n = 0;
        }
        int getn(){return n;}

        void print(){
            Node* cur = head;
            while(cur){
                cout<<cur->val<<"->";
                cur = cur->next;
            }
            cout<<endl;
        }

        void insertfront(int val){
            Node* newNode = new Node;
            newNode->val = val;
            newNode->next = head;
            head = newNode;
            n++;
        }
        //Challenge 2
        void insertattheend( int value){
            Node *newNode = new Node;
            newNode->val = value;
            newNode->next = nullptr;
            Node *cur = head;
            while (cur->next) cur = cur->next; 
            cur->next = newNode;
            n++;
        }
        
        // challenge 3
        void insert(int target, int value){
            if (target == 0){
                insertfront(value);
                n++;
            }
            if (target == n){
                insertattheend(value);
                n++;
            }
            Node *newnode = new Node;
            newnode->val = value;
            Node *cur = head;
            while (cur->val != target && cur->next != nullptr)
                cur = cur->next;
            newnode->next = cur->next;
            cur->next = newnode;
        }
};




int main(){
    ListNode Linkedlist; 
    Linkedlist.insertfront(1000);
    Linkedlist.insertattheend(10);
    Linkedlist.print();
}