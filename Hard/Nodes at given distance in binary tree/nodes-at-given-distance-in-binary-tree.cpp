//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

  void func(Node* root, int i, int k, vector<int> &ans)
    {
        if(root == NULL)
        return;
        
        if(i == k)
        {
            ans.push_back(root->data);
            return;
        }
        
        func(root->left, i+1, k, ans);
        func(root->right, i+1, k, ans);
    }
    
    void findPath(Node* root, int val, vector<Node*> &path, bool &var)
{
    if(root == NULL)
    return; 
    
    if(var==false)
    path.push_back(root);
        
    if(root->data == val)
    {
        var = true;
        return; 
    }
    
    if(var == false)
    findPath(root->left, val, path, var);
    
    if(var == false)
   findPath(root->right, val, path, var);
    
    if(var == false)
    path.pop_back();
    
    return;
}

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
        vector<Node*> path;
        bool var = false;
        
        findPath(root, target, path, var);
        
        int n = path.size();
        Node* temp = path[n-1];
        
        func(temp,0,k,ans);
        
        int p = 2, i = n-2;
        
        while(p<=k && i>=0)
        {
            temp = path[i];
            // cout<<temp->data<<endl;
            Node* node = path[i+1];
            
            if(temp->left && temp->left->data == node->data)
            {
                // cout<<"right";
                func(temp->right, p, k, ans);
            }
            else if(temp->right && temp->right->data == node->data)
            {
                // cout<<"left";
                func(temp->left, p, k, ans);
            }
            
            
            p++;
            i--;
        }
        
        if(n-k-1>=0)
        ans.push_back(path[n-k-1]->data);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends