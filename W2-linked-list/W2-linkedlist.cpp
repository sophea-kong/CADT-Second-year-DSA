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
            cur = head;
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
                cur = head;
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
            cur = head;
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
            if (target < 0 || target >= n){
                cout<<"target is out of range."<<endl;
                return;
            }
            cur = head;
            for(int i=0;i<target-1;i++) cur = cur->next;
            if(cur->next == nullptr){
                deleteback();
                return;
            }
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        //Challenge 7
        void _traverse(){
            cur = head;
            while (cur){
                cout<<cur->val<<"->";
                cur = cur->next;
            }
            cout<<endl;
        }
        //Challenge 8
        void swapNode(int node1, int node2) {
            if (node1 == node2) return;

            if (node1 > node2) swap(node1, node2);

            Node *prev1 = nullptr, *prev2 = nullptr;
            Node *n1 = head, *n2 = head;

            for (int i = 0; i < node2; ++i) {
                if (i < node1) {
                    prev1 = n1;
                    n1 = n1->next;
                }
                prev2 = n2;
                n2 = n2->next;
            }

            if (!n1 || !n2) return;
            if (n1->next == n2) {
                if (prev1) prev1->next = n2;
                else head = n2;

                n1->next = n2->next;
                n2->next = n1;
            } else {
                Node* temp = n2->next;

                if (prev1) prev1->next = n2;
                else head = n2;

                if (prev2) prev2->next = n1;
                else head = n1;

                n2->next = n1->next;
                n1->next = temp;
            }
        }
        void swapValue(int node1, int node2){
            cur = head;
            Node* n1 = nullptr;
            Node* n2 = nullptr;
            for(int i=0;i<n;i++){
                if (i == node1-1){
                    n1 = cur;
                } else if (i == node2-1){
                    n2 = cur;
                }
                cur = cur->next;
            }
            int temp = n1->val;
            n1->val = n2->val;
            n2->val = temp;
        }

        //Challenge 9
        int search(int target){
            cur = head;
            int location = 1;
            while(cur){
                if (cur->val == target){
                    return location;
                }
                location++;
                cur = cur->next;
            }
            cout<<"value not found."<<endl;
            return 0;
        }
};




int main(){
    ListNode Linkedlist; 
    Linkedlist.insertfront(1000);
    Linkedlist.insertfront(19);
    Linkedlist.insertfront(80);
    Linkedlist.insertattheend(10);
    Linkedlist.insert(2,22);
    Linkedlist.print();
    cout<<(Linkedlist.search(80));
    Linkedlist.swapNode(2,3);
    Linkedlist.print();
    Linkedlist.swapValue(3,4);
    Linkedlist.print();
}