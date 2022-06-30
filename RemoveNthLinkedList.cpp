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

void deleteAt(node* &head,int k){
    int n=ListSize(head);
    node* temp=head;
    for(int i=1;i<(n-k+1)-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void removeFromEnd(node* &head,int k){
    int n=ListSize(head);
    if(n==k){
        head=head->next;
    }else{
        node* fast=head->next;
        node* slow=head;
        //node* temp=head->next;
        for(int i=1;i<=k;i++){
            fast=fast->next;
            //temp=temp->next;
        }
        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
    }
}



int main(){

    cout<<"LinkedList Size:";int n;cin>>n;
    node* head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }

    cout<<"Give the value of N: ";int k;cin>>k;
    cout<<"New array:\n";
    //deleteAt(head,k);
    removeFromEnd(head,k);
    show(head);



    return 0;
}