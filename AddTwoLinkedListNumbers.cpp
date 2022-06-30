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

void addTwoNumbers(node* &head1,node* &head2,node* &ans){
    // node* ans=NULL;
    // node* temp=ans;
    int carry=0;
    while((head1!=NULL || head2!=NULL) || carry){
        int sum=0;
        if(head1!=NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2!=NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        sum += carry;
        carry=sum/10;
        add(ans,sum%10);
        // node* head= new node();
        // head->data=(sum%10);
        // temp->next=head;
        // temp=temp->next;
    }
    //return ans;
}



int main(){

    cout<<"First LinkedList Size:";int n1;cin>>n1;
    node *head1=NULL;
    cout<<"First LinkedList elements: \n";
    for(int i=0;i<n1;i++){
        int x;cin>>x;
        add(head1,x);
    }
    //reverseList(head1);
    cout<<"Second LinkedList Size:";int n2;cin>>n2;
    node *head2=NULL;
    cout<<"Second LinkedList elements: \n";
    for(int i=0;i<n2;i++){
        int x;cin>>x;
        add(head2,x);
    }
    //reverseList(head2);
    /*int num1=0;
    while(head1){
        num1=10*num1 +(head1->data);
        head1=head1->next;
    }cout<<"Num1: "<<num1<<endl;
    int num2=0;
     while(head2){
        num2=10*num2+(head2->data);
        head2=head2->next;
    }cout<<"Num2: "<<num2<<endl;

    int num=num1+num2;
    int temp=num;
    node* head=NULL;
    do{
        int r=num%10;
        num=num/10;
        add(head,r);
    }while(num>0);
    show(head);*/
    node* ans=NULL;
    addTwoNumbers(head1,head2,ans);
    show(ans);




    return 0;
}