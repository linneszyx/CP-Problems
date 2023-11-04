//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       string s1,s2;
        struct Node* head=first;
        while(first->next!=NULL)
        {
            s1+=to_string(first->data);
            first=first->next;
        }
        s1+=to_string(first->data);
        first->next=second;
        while(second!=NULL)
        {
            s2+=to_string(second->data);
            second=second->next;
        }
        int n=s1.size(),m=s2.size();
        int carry=0;
        first=head;
        struct Node* prev=NULL;
        vector<int> v;
        while(m and n)
        {
            int ans=((s1[--n])-'0')+((s2[--m])-'0')+carry;
            carry=ans/10;
            v.push_back((ans%10));
        }
        if(n)
            while(n)
            {
                int ans=((s1[--n])-'0')+carry;
                carry=ans/10;
                v.push_back((ans%10));
            }
            
        else
           while(m)
            {
                int ans=((s2[--m])-'0')+carry;
                carry=ans/10;
                v.push_back((ans%10));
            }
        if(carry) v.push_back(carry);
        reverse(v.begin(),v.end());
        for(auto const &x:v){first->data=x;prev=first;first=first->next;}
        prev->next=NULL;
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends