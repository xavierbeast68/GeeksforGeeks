//* https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
//* https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int data;
        cin >> data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin >> data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
Node *sortedMerge(Node *list1, Node *list2)
{
    // code here
    Node *mergedLL = new Node(-1);
    Node *temp = mergedLL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            // ListNode *tempo = new ListNode(list1->val);
            // temp->next = tempo;
            temp->next = new Node(list1->data);
            temp = temp->next;
            list1 = list1->next;
        }
        else
        {
            // ListNode *tempo = new ListNode(list2->val);
            // temp->next = tempo;
            temp->next = new Node(list2->data);
            temp = temp->next;
            list2 = list2->next;
        }
    }

    while (list1 != NULL)
    {
        // ListNode *tempo = new ListNode(list1->val);
        // temp->next = tempo;
        temp->next = new Node(list1->data);
        temp = temp->next;
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        // ListNode *tempo = new ListNode(list2->val);
        // temp->next = tempo;
        temp->next = new Node(list2->data);
        temp = temp->next;
        list2 = list2->next;
    }

    return mergedLL->next;
}