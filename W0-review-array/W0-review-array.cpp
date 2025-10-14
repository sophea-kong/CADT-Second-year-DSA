#include <iostream>

using namespace std;

void input(int * p_arr, int pos, int val, int &n, int size = 10){
    if(pos >= size || pos > n){
        cout<<"Error!"<<endl;
        return;
    }
    p_arr[pos] = val;
    n = (pos < n)? n: n+1;
}
void insert(int* ptr_arr, int pos, int val, int &n, int size = 10){
    if (n >= size){
        cout << "Error! Array is full." << endl;
        return;
    }
    if (pos < 0 || pos > n){
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = n; i > pos; i--) {
        ptr_arr[i] = ptr_arr[i - 1];
    }

    ptr_arr[pos] = val;
    n++;
}

void deletes(int* ptr_arr, int pos,int &n,int size = 10){
    if (!ptr_arr){
        cout<<"array is empty"<<endl;
        return;
    }
    // position is out of range
    if (pos >= n || pos < 0){
        cout<<"index out of range"<<endl;
        return;
    }
    ptr_arr[pos] = 0;
    for (int i =pos;i<n;i++){
        ptr_arr[i] = ptr_arr[i+1];
    }
    n--;
}
int main(){

    int a[10] = {1,2};
    int n = 2;
    insert(a,0,1,n);
    input(a,3,6,n);
    deletes(a,3,n);
    for(int i = 0; i < n; i++){
        cout<<"Value "<<i<<": "<<a[i]<<endl;
    }

    return 0;
}
