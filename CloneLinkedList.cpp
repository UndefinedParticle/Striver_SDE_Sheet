#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* bottom;
};

void add(Node* &head,int newData){
    Node* newNode=new Node();
    newNode->data=newData;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void show(Node* head){
    cout<<"[ ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<"]";cout<<endl;
}

int ListSize(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;

}

Node* cloneList(Node* head){
    
    // Copying the original Nodes into another Node
    Node* temp=head;
    Node* nex=temp->next;
    while(temp->next != NULL){
        Node* ans=new Node();
        ans->data=temp->data;
        temp->next=ans;
        ans->next=nex;
        temp=nex;
        nex=temp->next;
    }
    Node* ans=new Node();
    ans->data=temp->data;
    temp->next=ans;
    ans->next=NULL;


    // Creating the bottom links
    temp=head;
    Node* temp1=temp->next;
    while(temp->next->next != NULL){
        temp1->bottom=temp->bottom->next;
        temp=temp->next->next;
        temp1=temp->next->next;
    }
    temp1->bottom=temp->bottom->next;


    // Separating the original head Nodes and ANS Nodes
    temp=head;
    temp1=temp->next;
    ans=temp1;
    while(temp1->next != NULL){
        temp->next=temp->next->next;
        temp1->next=temp1->next->next;

        temp=temp->next;
        temp1=temp1->next;
    }


    return ans;
}

/*Node* copybottomList(Node* head) {
        
        if(!head) 
            return NULL; 
        Node* temp = head;
        while(temp){
            Node* ans = new Node();
            ans->data=temp->data;
            ans->next = temp->next; 
            temp->next = ans;
            temp = ans->next;
        }
		
		
        temp = head; 
        while(temp){
            temp->next->bottom = (temp->bottom)?temp->bottom->next:NULL; 
            temp = temp->next->next; 
        }
		
		
        Node* ans = head->next;
        temp = head->next;
        while(head){ 
            head->next = temp->next;
            head = head->next; 
            if(!head) 
                break; 
            temp->next = head->next; 
            temp = temp->next;
        }
        return ans;
        
}*/


int main(){

    cout<<"LinkedList Size:";int n;cin>>n;
    Node *head=NULL;
    cout<<"LinkedList elements: \n";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        add(head,x);
    }
    show(cloneList(head));



    return 0;
}