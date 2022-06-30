#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

void add(node* &head,int newData){
    node* newnode=new node();
    newnode->data=newData;
    if(head==NULL){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void show(node* head){
    cout<<"[ ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<"]";cout<<endl;
}
int ListSize(node* head){
    int count=0;
    node* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;

}


int main(){

    cout<<"LinkedList Size:";int n;cin>>n;
    node* head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }




    return 0;
}