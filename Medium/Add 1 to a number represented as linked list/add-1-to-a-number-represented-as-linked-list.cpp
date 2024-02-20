//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
       Node* reverse(Node* node)
    {
        Node* prev{nullptr};
        Node* curr{node};
        Node* next{node->next};
        
        while(curr)
        {
            curr->next = prev;
            
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }
        
        
        return prev;
    }

public:
    Node* addOne(Node *head) 
    {
        int ripple{1};
        head = reverse(head);
        
        Node* curr{head};
        Node* prev{head};
        
        while(curr && ripple)
        {
            int sum{ripple + curr->data};
            
            ripple = sum / 10;
            curr->data = sum % 10;
            
            prev = curr;
            curr = curr->next;
        }
        
        if(ripple) prev->next = new Node(ripple);
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends