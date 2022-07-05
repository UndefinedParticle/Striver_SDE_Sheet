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

void createCycle(node* &head,int a,int b){
    int ca=1,cb=1;
    node* temp1=head;
    node* temp2=head;
    while(ca!=a || cb!=b){
        if(ca!=a){
            ca++;
            temp1=temp1->next;
        }
        if(cb!=b){
            cb++;
            temp2=temp2->next;
        }
    }
    temp2->next=temp1;
}

node* startingPoint(node* head){
    if(head == NULL||head->next == NULL) return NULL;
    node* slow=head;
    node* fast=head;
    node* start=head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(slow != start) {
                slow = slow->next;
                start = start->next;
            }
            return start;
        }
    }
    return NULL;
}



int main(){

    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    createCycle(head,3,7);
    node* ans=startingPoint(head);
    if(ans==NULL)
        cout<<"No Cycle\n";
    else{
        node* temp=head;
        int pos=1;
        while(temp!=ans){
            pos++;
            temp=temp->next;
        }
        cout<<"Starting point of loop in a Linked List is: "<<pos<<endl;
    }




    return 0;
}