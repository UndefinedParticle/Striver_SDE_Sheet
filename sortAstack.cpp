#include<iostream>
#include<stack>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

void mySort(stack<int> &st,int x){
    if(st.empty() || x>st.top()){
        st.push(x);
        return;
    }
    int n=st.top();
    st.pop();
    mySort(st,n);
    st.push(n);
}


void sortStack(stack<int> &st){
    if( !st.empty()){
        int x=st.top();
        st.pop();
        sortStack(st);
        mySort(st,x);

    }
}


int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements: \n";
    int a[n];
    loop(i,0,n){
        cin>>a[i];
    }







    return 0;
}