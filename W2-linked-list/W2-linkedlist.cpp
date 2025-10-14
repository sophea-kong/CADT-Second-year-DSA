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
        void insertattheend(int value){
            Node *newNode = new Node;
            newNode->val = value;
            newNode->next = nullptr;
            if (head == nullptr){
                head= newNode;
            } else {
                Node *cur = head;
                while (cur->next) cur = cur->next; 
                cur->next = newNode;
            }
            n++;
        }
        
        // challenge 3
        void insert(int target, int value){
            if (target > n){
                cout<<"index out of range"<<endl;
                return;
            }
            if (target == n){
                insertattheend(value);
                return;
            }
            if (target < 0){
                cout<<"the position cant be negative."<<endl;
                return;
            }
            if( target == 0 ){
                insertfront(value);
                return;
            }
            Node* newNode = new Node;
            newNode->val = value;
            Node* cur = head;
            for (int i=0;i<target-1;i++) cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
            n++;
        }
        // challenge 4
        void deletefront(){
            if (head == nullptr){
                cout<<"the list is empty."<<endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
            n--;
        }
        //Challenge 5
        void deleteback(){
            if (head == nullptr){
                cout<<"the list is empty."<<endl;
                return;
            }
            if(n == 1){
                delete head;
                head = nullptr;
                n--;
                return;
            }
            Node* cur = head;
            while(cur->next->next) cur = cur->next;
            Node* temp = cur->next;
            cur->next = nullptr;
            delete temp;
            n--;
        }
        //Challenge 6
        void deletemiddle(int target){
            if (target == 0){
                deletefront();
                return;
            }
            if (target > n){
                cout<<"target is out of range."<<endl;
                return;
            }
            Node* cur = head;
            for(int i=0;i<target-1;i++) cur = cur->next;
            if(cur->next == nullptr)[
                deleteback();
                return;
            ]
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }

};




int main(){
    ListNode Linkedlist; 
    Linkedlist.insertfront(1000);
    Linkedlist.insertfront(19);
    Linkedlist.insertfront(80);
    Linkedlist.insertattheend(10);
    Linkedlist.insert(2,22);
    Linkedlist.deletefront();
    Linkedlist.print();
    Linkedlist.deletemiddle(1);
    Linkedlist.print();
}