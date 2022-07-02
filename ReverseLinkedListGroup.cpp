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

int ListSize(node* head){
    int count=0;
    node* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;

}

node* reverseList(node* head,int k){
    int n=ListSize(head);
    node* temp=new node();
    temp->data=0;
    temp->next=head;
    node* prev=temp;
    node* curr=head;
    node* nex=head;
    
    while(k<=n){
        curr=prev->next;
        nex=curr->next;
        for(int i=1;i<k;i++){
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        n=n-k;
    }
    return temp->next;

}


int main(){
    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }

    cout<<"Group Size: ";int k;cin>>k;
    
    cout<<"FInal Ans:\n";
    
    show(reverseList(head,k));



    return 0;
}