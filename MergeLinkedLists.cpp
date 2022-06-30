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
int middleElement(node* head){
    node* slow=head;
    node *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

node* myMerge(node* &head1,node* &head2){
    node* temp1=head1;
    node* temp2=head2;
    node* ans=NULL;
    while(temp1 && temp2){
        if(temp2->data <= temp1->data){
            add(ans,temp2->data);
            temp2=temp2->next;
        }else{
            add(ans,temp1->data);
            temp1=temp1->next;
        }
    }

    while(temp1){
        add(ans,temp1->data);
        temp1=temp1->next;
    }
    while(temp2){
        add(ans,temp2->data);
        temp2=temp2->next;
    }


    return ans;
}
void swap(node* &head1,node* &head2){
    node* temp=head1;
    head1=head2;
    head2=temp;
}
node* Merge(node* head1,node* head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data > head2->data){
        swap(head1,head2);
    }

    node* ans=head1;
    while(head1!=NULL && head2 !=NULL){
        node* temp=NULL;
        while(head1!=NULL && head1->data <= head2->data){
            temp=head1;
            head1=head1->next;
        }
        temp->next=head2;
        swap(head1,head2);
    }

    return ans;
}




int main(){
    cout<<"First LinkedList Size:";int n1;cin>>n1;
    node *head1=NULL;
    cout<<"First LinkedList elements: \n";
    for(int i=0;i<n1;i++){
        int x;cin>>x;
        add(head1,x);
    }
    cout<<"Second LinkedList Size:";int n2;cin>>n2;
    node *head2=NULL;
    cout<<"Second LinkedList elements: \n";
    for(int i=0;i<n2;i++){
        int x;cin>>x;
        add(head2,x);
    }
    node* ans1=myMerge(head1,head2);
    cout<<"Final Ans(1): \n";
    show(ans1);

    node* ans2=Merge(head1,head2);
    cout<<"Final Ans(2): \n";
    show(ans2);


    return 0;
}