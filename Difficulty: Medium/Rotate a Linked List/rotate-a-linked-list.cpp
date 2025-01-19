//{ Driver Code Starts
// Initial Template for C++
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

#define all(p)  p.begin(),p.end()
#define vi vector<int>
#define sz(x) ((int)x.size())
#define pb push_back
class Solution {
  public:
    Node* rotate(Node* head, int k) {
     vi v;
     int n=0;
     Node * t = head;
     while(t!=nullptr) {
         v.pb(t->data);
         t=t->next;
         n++;
     } 
      t=head;
      reverse(v.begin(),v.begin()+(k%n));
      reverse(v.begin()+(k%n),v.end());
      reverse(all(v));
      for(int i=0;i<sz(v);i+=1) {
          t->data=v[i];
          t=t->next;
      }
      return head;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends