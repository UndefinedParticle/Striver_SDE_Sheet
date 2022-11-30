#include<iostream>
#include<algorithm>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

class LRUCache {
public:
    struct node{

        int key,val;
        node *next,*prev;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };

    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int size;
    unordered_map<int,node*> mp;


    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(node *newNode){
        node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(node *curNode){
        node *prevNode=curNode->prev;
        node *nextNode=curNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }



    
    int get(int key) {

        if(mp.find(key) != mp.end()){
            node *temp=mp[key];
            int ans=temp->val;
            deleteNode(mp[key]);
            mp.erase(key);
            add(temp);
            mp[key]=head->next;
            return ans;
        }

    return -1;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            node *temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==size){
            node *temp=tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }

        add(new node(key,value));
        mp[key]=head->next;
        
    }
};










int main(){
    
    LRUCache lfu(2);
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