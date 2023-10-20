//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    class Node{
      public:
          int data;
          Node* next;
          
          Node(int data) {
              this->data = data;
              next = NULL;
          }
    };
    Node* tail = NULL;
    map<int, int> mp;
    
    void addNode(Node* &root, int data){
        if(!root) {
            root = new Node(data);
            tail = root;
            return;
        }
        
        Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = tail->next; 
    }
    void addnew(Node* &root, int data) {
        mp.erase(root->data);
        root = root -> next;
        tail -> next = new Node(data);
        tail = tail -> next;
    }
    void updateNode(Node* &root, int node) {
        if(tail -> data == node) return;
        Node* prev = NULL;
        Node* curr = root;
        
        while(curr->data != node) {
            prev = curr;
            curr = curr->next;
        }
        
        if(root == curr) {
            root = root -> next;
            curr->next = NULL;
        }
        else {
            prev -> next = curr -> next;
            curr -> next = NULL;
        }
        
        tail -> next = curr;
        tail = curr;
    }
    int pageFaults(int N, int C, int pages[]){
        // code here
        tail = NULL;
        mp.clear();
        Node* root = NULL;
        int ans = 0;
        
        int cache = 0;
        int i = 0;
        for(; cache < C and i < N; ++i) {
            if(mp.find(pages[i]) != mp.end()) {
                updateNode(root, pages[i]);
            }
            else {
                    ans++;
                    addNode(root, pages[i]);
                    mp[pages[i]]++;
                    cache++;
            }
        }
        
        for(; i < N; ++i) {
            if(mp.find(pages[i]) != mp.end()) {
                updateNode(root, pages[i]);
            }
            else {
                    ans++;
                    addnew(root, pages[i]);
                    mp[pages[i]]++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends