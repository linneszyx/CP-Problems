//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    Node* reverse(Node* head) {
     Node *tail = head;
     while(tail->next!=head) tail=tail->next;
     Node *prev=tail;
     Node *next=NULL;
     Node *curr = head;
     while(curr!=tail){
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
     }
     curr->next=prev;
     prev=curr;
     return prev;
        
    }
    Node* deleteNode(Node* head, int key) {
      if(head->data==key) {
          Node *temp1 =head;
          Node *temp2=head->next;
          while(temp2->next!=head) temp2=temp2->next;
          temp2->next=temp1->next;
          temp1->next=NULL;
          delete temp1;
          head=temp2->next;
      }
      else {
          Node *temp1=head->next;
          Node *temp2=head;
          while(temp1!=head){
              if(temp1->data==key){
                  temp2->next=temp1->next;
                  temp1->next=NULL;
                  delete temp1;
                  break;
              }
              else{
                  temp2=temp1;
                  temp1=temp1->next;
              }
          }
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends