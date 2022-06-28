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
int middle(node* head){

    int n=ListSize(head);
    int mid=n/2;
    
    node* temp=head;
    for(int i=1;i<=mid;i++){
        temp=temp->next;
    }

    return temp->data;

}

int middleElement(node* head){
    node* slow=head;
    node *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int main(){
    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    cout<<"List Size: "<<ListSize(head)<<endl;
    cout<<"Middle Element is : "<<middle(head)<<endl;
    cout<<"Middle Element is : "<<middleElement(head)<<endl;


    return 0;
}