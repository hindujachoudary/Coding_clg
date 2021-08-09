#include<bits/stdc++.h>
using namespace std;

struct Node { 
    int data;
    Node *next; 
};

Node* newnode(int x){
    Node* temp=new Node();
    temp->data=x;  
    temp->next=NULL;
    return temp;
}

Node* segregate(Node *head){
    Node *even,*odd,*estart,*ostart,*cur;
    estart=ostart=NULL; 
    cur=head;
    
    while(cur){
        if(cur->data%2==0){
           if(estart==NULL)
                estart=even=cur;
         else{
                even->next=cur; 
                even = even->next;
            }
       }
       else{
           if(ostart==NULL)
                ostart=odd=cur;
            else{
                odd->next=cur;
                odd=odd->next;
            }
       }
       cur=cur->next;
    }
    odd->next=NULL; 
    if(!estart)
        return ostart;

    even->next=ostart;
    
    return estart;
}
int main(){
    int t,n,x,i;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>x;
        Node *head,*temp,*prev;
        head=newnode(x);
        temp=head;
        prev=head;
        for(i=0;i<n-1;i++){
            cin>>x;
            temp->next=newnode(x);
            temp=temp->next;
        }
        temp=segregate(head);
        while(temp->next){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    return 0;
}
