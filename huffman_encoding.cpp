//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
class cmp{
    public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};
class Solution
{
	public:
        void traverse(Node *root, string s, vector<string> &ans) {
            if(root == NULL) return;
            if(root->left == NULL && root->right == NULL) {
                ans.push_back(s);
                return;
            }
            traverse(root->left, s + "0", ans);
            traverse(root->right, s + "1", ans);
        }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
            priority_queue<Node*, vector<Node*>, cmp> pq;
            for(int i = 0; i < N; i++) {
                Node *temp = new Node(f[i]);
                pq.push(temp);
            }
            while(pq.size() > 1) {
                Node *a = pq.top();
                pq.pop();
                Node *b = pq.top();
                pq.pop();
                Node *temp = new Node(a->data + b->data);
                temp->left = a;
                temp->right = b;
                pq.push(temp);
            }
            Node *root = pq.top();
            vector<string> ans;
            traverse(root, "", ans);
            return ans;   
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends