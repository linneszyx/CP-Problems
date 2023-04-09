/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
 
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node *newNode = new Node(node->val);
        unordered_map<Node*, Node*> m;
        m[node] = newNode;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            for (Node *n : cur->neighbors) {
                if (m.find(n) == m.end()) {
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[cur]->neighbors.push_back(m[n]);
            }
        }
        return newNode;
    }
};
// @lc code=end

