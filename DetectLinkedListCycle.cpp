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

// Time Complexity: O(N)
// Space Complexity: O(N)
bool detectCycle(node* head){
    unordered_set<node*> st;
    while(head != NULL){
        if(st.find(head) != st.end()){
            return true;
        }
        st.insert(head);
        head=head->next;
    }
    return false;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
bool cycleDetect(node* head) {
    if(head == NULL) return false;
    node* fast = head;
    node* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}



int main(){
    cout<<"LinkedList Size:";int n;cin>>n;
    node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    createCycle(head,2,4);
    (detectCycle(head)==true)? cout<<"Cycle detected\n":cout<<"Cycle not detected\n";




    return 0;
}