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


// Time Complexity: O(N)
// Space Complexity: O(N)
bool isPalindrome(node* head){
    vector<int> a;
    while(head != NULL){
        a.emplace_back(head->data);
        head=head->next;
    }
    for(int i=0;i<a.size()/2;i++){
        if(a[i] != a[a.size()-1-i])
            return false;
    }
    return true;

}

node* reverseList(node* head){
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
    return head;

}


// Time Complexity: O(N/2)
// Space Complexity: O(1)
bool Palindrome(node* head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    slow->next=reverseList(slow->next);
    slow=slow->next;
    node* temp=head;
    while(slow!=NULL){
        if(temp->data != slow->data)
            return false;
        temp=temp->next;
        slow=slow->next;
    }
    return true;
}


int main(){
    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    (isPalindrome(head)==true)? cout<<"Palindrome\n":cout<<"Not Palindrome\n";

    (Palindrome(head)==true)? cout<<"Palindrome\n":cout<<"Not Palindrome\n";





    return 0;
}