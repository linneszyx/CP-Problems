//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head){
  if(head == NULL){
            return head;
        }
        
        Node* prev= NULL;
        Node* curr = head;
        
        while(curr != NULL){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        
        return prev;
}
    Node *compute(Node *head)
    {
            Node* revHead = reverse(head);
        
        Node* prev = revHead;
        Node* curr = revHead->next;
        
        while(curr != NULL){
            if(prev->data > curr->data){
                curr = curr->next;
            }
            else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        if(curr == NULL){
            prev->next = curr;
        }
        
        
        Node* ans = reverse(revHead);
        
        return ans;
        // your code goes here
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends