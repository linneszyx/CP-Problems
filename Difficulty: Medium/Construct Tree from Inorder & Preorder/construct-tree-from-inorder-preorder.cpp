//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

#define vi vector<int>
class Solution {
  public:
  int help(int i,int j,int val,vi &inorder) {
      for(int k=i;k<=j;k++) if(inorder[k]==val) return k;
      return i;
  }
    Node *f(vi &inorder,vi &preorder,int i1,int j1,int i2,int j2) {
        if(i2>j2) return NULL;
        Node *root = new Node(preorder[i2]);
        int idx = help(i1,j1,preorder[i2],inorder);
        root->left = f(inorder,preorder,i1,idx-1,i2+1,i2+idx-i1);
        root->right = f(inorder,preorder,idx+1,j1,i2+idx-i1+1,j2);
        return root;
    }
    Node *buildTree(vi &inorder, vi &preorder) {
     int n = inorder.size();
     return f(inorder,preorder,0,n-1,0,n-1);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends