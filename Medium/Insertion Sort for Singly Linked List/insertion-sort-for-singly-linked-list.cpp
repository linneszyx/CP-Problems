//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insert(Node* key, Node* cur){

        int temp = key->data;

        key->data = cur->data;

        cur->data = temp;

        return cur;

    }

    Node* insertionSort(struct Node* head_ref)

    {

        if(!head_ref || !head_ref->next) return head_ref;

        Node* cur = head_ref;

        while(cur){

            Node* key ;

            int mindata = cur->data;

            Node* right= cur;

            while(right){

                if(mindata >= right->data){

                    key = right;

                    mindata = right->data;

                }

                right= right->next;

            }

            cur= insert(key, cur);

            cur= cur->next;

        }

        return head_ref;

    }

 
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends