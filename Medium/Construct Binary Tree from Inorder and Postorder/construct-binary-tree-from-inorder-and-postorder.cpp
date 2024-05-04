//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    Node *f(int &pi,int is,int ie,int s,int in[],int post[]){
        if(pi<0) return NULL;
        if(is>ie) return NULL;
        int idx = is;
        for(;idx<=ie;++idx)
            if(post[pi]==in[idx]) break;
        Node * root = new Node(post[pi--]);
        root->right = f(pi,idx+1,ie,s,in,post);
        root->left = f(pi,is,idx-1,s,in,post);
        return root;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int pi = n-1;
        return f(pi,0,n-1,n,in,post);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends