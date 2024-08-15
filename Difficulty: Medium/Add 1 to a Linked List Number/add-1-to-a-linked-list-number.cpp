//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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

class Solution {
  public:
    Node* reverse(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = temp;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void print(Node *head)
    {
        Node *temp = head;
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void sum(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        Node *new_node = NULL;
        int sum = 0, carry = 1;
        while(temp)
        {
            sum = temp->data + carry;
            if(sum >= 10)
            {
                carry = sum/10;
                sum = sum%10;
                
            }
            else
                carry = 0;
            
            prev = temp;
            temp->data = sum;    
            temp = temp->next;
            //sum = 0;
        }
        if(carry)
        {
            new_node = (Node *)malloc(sizeof(struct Node));
            new_node->data = carry;
            new_node->next = NULL;
            prev->next = new_node;
            //cout << prev->data;
        }
    }
    Node* addOne(Node* head) 
    {
        Node *rev = reverse(head);
        //print(rev);
        sum(rev);
        rev = reverse(rev);
        return rev;
        // Your Code here
        // return head of list after adding one
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends