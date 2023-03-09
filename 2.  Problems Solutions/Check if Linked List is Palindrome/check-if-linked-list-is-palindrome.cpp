//* https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
//* https://leetcode.com/problems/palindrome-linked-list/editorial/

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // slow-fast technique or two-runners pointer technique
    Node *findMid(Node *head)
    {
        Node *slow, *fast;
        slow = fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    Node *reverseList(Node *midNode)
    {
        Node *prev = NULL;
        Node *curr = midNode;
        Node *Next;

        while (curr != NULL)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Your code here

        if (head->next == NULL)
        {
            return true;
        }

        Node *midNode = findMid(head);

        Node *left = head;
        Node *right = reverseList(midNode);

        while (right != NULL)
        {
            if (left->data != right->data)
            {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends