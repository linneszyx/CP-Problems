//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
       struct Node* revList(struct Node* curr)
    {
        struct Node* prev=NULL;
        while(curr!=NULL)
        {
            struct Node* temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    void rearrange(struct Node *odd)
    {
        //temporary nodes
        struct Node* curr=odd;
        struct Node* next=curr->next;
        struct Node*list1=odd;
        struct Node* list2=odd->next;
        
        //separate 2 alternate lists by updating links
        while(next!=NULL)
        {
            
            curr->next=next->next;
            curr=next;
            next=next->next;
        }
        
        //find tail of list 1
        while(list1->next!=NULL)
            list1=list1->next;
        
        //reverse the list 2 and store reversed lists head
        list2 = revList(list2);
        
        //append reversed list 2 at next of tail of list 1    
        list1->next=list2;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends