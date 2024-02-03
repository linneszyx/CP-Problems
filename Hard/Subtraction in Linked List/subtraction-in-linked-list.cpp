//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
Node *reverse(Node *head)
    {
        Node *curr=head,*prev=NULL;
        while(curr)
        {
            Node *next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 && head1->data==0)
        {
            head1=head1->next;
        }
        while(head2 && head2->data==0)
        {
            head2=head2->next;
        }
        int n1=0,n2=0;
        Node *curr1=head1,*curr2=head2;
        while(curr1)
        {
            n1++;
            curr1=curr1->next;
        }
        while(curr2)
        {
            n2++;
            curr2=curr2->next;
        }
        if(n1 < n2)
        {
            swap(head1,head2);
        }
        else if(n1 == n2)
        {
            curr1=head1;
            curr2=head2;
            while(curr1)
            {
                if(curr1->data > curr2->data)
                {
                    break;
                }
                else if(curr1->data < curr2->data)
                {
                    swap(head1,head2);
                    break;
                }
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }
        if(head1==NULL && head2==NULL)
        {
            return new Node(0);
        }
        //head1 has larger number
        //head2 has smaller number
        head1=reverse(head1);
        head2=reverse(head2);
        int borrow =0;
        Node *head=new Node(-1);
        Node *tail=head;
        while(head1 || head2)
        {
            int a = head1->data + borrow;
            int b=0;
            if(head2)
            {
                b=head2->data;
            }
            head1=head1->next;
            if(head2)
            {
                head2=head2->next;
            }
            
            if(a < b)
            {
                Node *temp=new Node(a+10-b);
                tail->next=temp;
                tail=temp;
                borrow = -1;
            }
            else
            {
                Node *temp = new Node(a-b);
                tail->next=temp;
                tail=temp;
                borrow=0;
            }
            
        }
        head=head->next;
        head = reverse(head);
        while(head && head->data == 0)
        {
            head=head->next;
        }
        if(head==NULL)
        {
            return new Node(0);
        }
        return head;
 
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends