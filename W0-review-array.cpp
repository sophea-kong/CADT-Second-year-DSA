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
void insert(int* ptr_arr, int pos,int val,int &n,int size = 10){
    // array is full
    if (n >= size){
        cout<<"Error!"<<endl;
        return;
    }
    // position is negative number
    if (pos < 0){
        cout<<"Position can not be a negative number."<<endl;
        return;
    }

    int temp[size];
    int j = 0;
    for (int i =pos;i<n;i++){
        temp[j] = ptr_arr[i];
        j++;
    }
    ptr_arr[pos] = val;
    j=0;
    for (int i=pos+1;i<n;i++){
        ptr_arr[i] = temp[j];
        j++;
    }
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
    int temp[size];
    int j = 0;
    for (int i =pos+1;i<n;i++){
        temp[j] = ptr_arr[i];
        j++;
    }
    j=0;
    for (int i=pos;i<n;i++){
        ptr_arr[i] = temp[j];
        j++;
    }
    n--;
    ptr_arr[n] = 0;
}
int main(){

    int a[10] = {1,2};
    int n = 2;

    input(a, 2, 10, n);
    input(a, 3, 15, n);
    input(a, 1, 25, n);
    input(a, 4, 6, n);
    insert(a , 0, -1,n);
    deletes(a,0,n);
    deletes(a,3,n);
    for(int i = 0; i < n; i++){
        cout<<"Value "<<i<<": "<<a[i]<<endl;
    }
    

    return 0;
}
