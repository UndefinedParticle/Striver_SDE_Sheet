#include<iostream>
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

node* rotateList(node* head,int k){
    int n=ListSize(head);
    int i=1;
    k=k%n;
    node* temp=head;
    //node* temp1=NULL;
    //temp1->next=head;
    node* newHead=head;
    while(temp->next != NULL){
        temp=temp->next;
        if(i<(n-k)){
            //temp1=temp1->next;
            newHead=newHead->next;
            i++;
        }
    }
    temp->next=head;
    node* ans=newHead->next;
    newHead->next=NULL;


    return ans;
}


int main(){

    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    cout<<"Value of K: ";int k;cin>>k;
    
    show(rotateList(head,k));




    return 0;
}