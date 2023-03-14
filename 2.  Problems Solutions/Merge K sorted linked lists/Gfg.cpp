// https://leetcode.com/problems/merge-k-sorted-lists/description/
// https://leetcode.com/problems/merge-k-sorted-lists/editorial/
// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/library/merge-k-sorted-linked-lists
// https://www.interviewbit.com/problems/merge-k-sorted-lists/
// https://www.youtube.com/watch?v=7wdont5Bgnk
// https://www.youtube.com/watch?v=RYJ3vs8qx10
// https://www.youtube.com/watch?v=q5a5OiGbT6Q



//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *lists[], int K)
    {
        // Your code here

        priority_queue<Node *, vector<Node *>, cmp> queue;
        Node *mergedLL = new Node(-1);
        Node *tail = mergedLL;

        for (int i = 0; i < K; i++)
        {
            if (lists[i] != NULL)
            {
                queue.push(lists[i]);
            }
        }

        if (queue.empty())
        {
            return NULL;
        }

        while (!queue.empty())
        {
            Node *temp = queue.top();
            queue.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL)
            {
                queue.push(temp->next);
            }
        }

        return mergedLL->next;
    }

    class cmp
    {
    public:
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
    };
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends