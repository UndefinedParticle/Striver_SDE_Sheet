#include<iostream>
#include<climits>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;i++)


class Stack {
    int *a;
    int tp;
    int size;
public:
    
    Stack(int capacity) {
        a = new int[capacity];
        tp=-1;
        size=capacity;
    }

    void push(int num) {
        if(tp==size) return;
        tp++;
        a[tp]=num;
    }

    int pop() {
        if(tp==-1) return tp;
        int temp=a[tp];
        tp--;
        return temp;
    }
    
    int top() {
        if(tp==-1) return tp;
        return a[tp];
    }
    
    int isEmpty() {
        if(tp==-1) return 1;
        return 0;
    }
    
    int isFull() {
        if(tp==size) return 1;
        return 0;
    }
    int Size(){
        if(tp==-1) return 0;
        return tp+1;
    }
};




int main(){

    Stack st(1000);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);
    cout<<"Size: "<<st.Size()<<endl;
    cout<<"Top: "<<st.top()<<endl;
    st.pop();cout<<"Popped.\n";
    cout<<"Size: "<<st.Size()<<endl;
    cout<<"Top: "<<st.top()<<endl;





    return 0;
}