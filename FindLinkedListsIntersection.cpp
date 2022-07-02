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

// Time Complexity: O(n*m)
// Space Somplexity: O(1)
node* intersection(node* head1,node* head2){
    while(head2 != NULL){
        node* temp=head1;
        while(temp != NULL){
            if(temp == head2)
                return head2;
            temp=temp->next;
        }
        head2=head2->next;
    }

    return NULL;

}

// Time Complexity: O(n+m)
// Space Somplexity: O(n)
node* intersection1(node* head1,node* head2){
    unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}

node* interSection2(node* head1, node* head2){
    node* temp1=head1;
    node* temp2=head2;
    while(temp1 != temp2){
        if(temp1==NULL)
            temp1=head2;
        else
            temp1=temp1->next;
        if(temp2 ==NULL)
            temp2=head1;
        else
            temp2=temp2->next;


        // temp1= (temp1==NULL)? head2:temp1->next;
        // temp2= (temp2==NULL)? head1:temp2->next;


    }

    return temp1;
}




int main(){
    cout<<"LinkedList Size:";int n1;cin>>n1;
    node *head1=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n1;i++){
        int x;cin>>x;
        add(head1,x);
    }

    cout<<"LinkedList Size:";int n2;cin>>n2;
    node *head2=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n2;i++){
        int x;cin>>x;
        add(head2,x);
    }


    node* ans=intersection(head1,head2);
    if(ans==NULL)
        cout<<"No Intersection\n";
    else
        cout<<"Intersection is: "<<ans<<endl;




    return 0;
}