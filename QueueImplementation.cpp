#include<iostream>
#include<climits>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;i++)


class Queue {
    int *a;
    int tp;
    int rear;
    //int capacity;
    int curSize=0;
public:
    Queue(int capacity) {
        a = new int[capacity];
        tp=-1;
        rear=-1;
        //this->capacity=capacity;
        curSize=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(curSize==0) return true;
        return false;
    }

    void enqueue(int data) {
        if(tp==-1 && rear==-1){
            tp++,rear++;
            a[rear]=data;
        }else{
            rear++;
            a[rear]=data;
        }
        curSize++;   
    }

    int dequeue() {
        if(curSize==0 || tp==-1) return -1;
        int temp=a[tp];
        tp++;
        curSize--;
        return temp;
    }

    int front() {
        if(curSize==0) return -1;
        return a[tp];
    }
     int Size(){
        return curSize;
    }
};




int main(){

    Queue st(1000);
    st.enqueue(1);
    st.enqueue(3);
    st.enqueue(5);
    st.enqueue(7);
    cout<<"Size: "<<st.Size()<<endl;
    cout<<"front: "<<st.front()<<endl;
    st.dequeue();cout<<"Popped.\n";
    cout<<"Size: "<<st.Size()<<endl;
    cout<<"front: "<<st.front()<<endl;





    return 0;
}