#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

void add(node* &head,int newData){
    node* newNode=new node();
    newNode->data=newData;
    if(head==NULL){
        head=newNode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void show(node* head){
    cout<<"[ ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<"]";cout<<endl;
}

void reverseList(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;
    
    while(curr){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    head=prev;
    //return head;

}



int main(){
    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    cout<<"Before reversing:\n";
    show(head);
    reverseList(head);
    cout<<"After reversing:\n";
    show(head);

    return 0;
}