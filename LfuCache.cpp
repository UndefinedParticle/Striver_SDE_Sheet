#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


struct node{
    int key,val,cnt;
    node *next;
    node *prev;
    node(int key,int val){
        this->key=key;
        this->val=val;
        cnt=1;
    }
};

struct List{
    int size;
    node *head;
    node *tail;
    List(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next = tail;
        tail->prev = head; 
        size=0;
    }


    void addFront(node *nd){
        node *temp=head->next;
        nd->next=temp;
        nd->prev=head;
        head->next=nd;
        temp->prev=nd;
        size++;
    }

    void deleteNode(node *nd){
        node *delPrev=nd->prev;
        node *delNext=nd->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }
};



class LFUCache {
public:
    map<int,node*> keyList;
    map<int,List*> freqList;
    int maxSize;
    int minFreq;
    int curSize;

    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        curSize=0;
    }

    void updateFreqList(node *nd){
        keyList.erase(nd->key);
        freqList[nd->cnt]->deleteNode(nd);
        if(nd->cnt == minFreq && freqList[nd->cnt]->size == 0){
            minFreq++;
        }

        List *nextHigherFreq=new List();
        if(freqList.find(nd->cnt + 1) != freqList.end()){
            nextHigherFreq=freqList[nd->cnt +1];
        }

        nd->cnt += 1;
        nextHigherFreq->addFront(nd);
        freqList[nd->cnt] = nextHigherFreq;
        keyList[nd->key]=nd;
    }
    
    
    
    int get(int key) {
        if(keyList.find(key) != keyList.end()){
            node *nd=keyList[key];
            int value=nd->val;
            updateFreqList(nd);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize == 0){
            return;
        }

        if(keyList.find(key) != keyList.end()){
            node *nd=keyList[key];
            nd->val=value;
            updateFreqList(nd);
        }else{
            if(curSize == maxSize){
                List *lst=freqList[minFreq];
                keyList.erase(lst->tail->prev->key);
                freqList[minFreq]->deleteNode(lst->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List *listFreq=new List();
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            node *nd=new node(key,value);
            listFreq->addFront(nd);
            keyList[key]=nd;
            freqList[minFreq]=listFreq;
        }
    }
};


int main(){
    
    LFUCache lfu(2);
    cout<<"Put: 1\nGet: 2\nExit: 0\n";
    int input;cin>>input;
    while(input!=0){
        if(input==1){
            cout<<"Key,Value: ";
            int key,value;
            cin>>key>>value;
            lfu.put(key,value);
        }else if(input==2){
            cout<<"key: ";
            int key;cin>>key;
            cout<<lfu.get(key)<<endl;
        }

        cout<<"Put: 1\nGet: 2\nExit: 0\n";
        cin>>input;
    }



    return 0;
}