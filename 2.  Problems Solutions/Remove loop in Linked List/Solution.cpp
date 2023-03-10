//* https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes

        Node *slow, *fast;
        slow = fast = head;
        bool cycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cycle = true;
                break;
            }
        }

        if (cycle == false)
        {
            return;
        }

        slow = head;
        // edge case, case of full cycle, ex=> 1->2->3->1
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends