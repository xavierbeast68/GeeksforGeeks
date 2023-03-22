//* https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://leetcode.com/problems/reverse-nodes-in-k-group/description/
//* https://www.youtube.com/watch?v=Of0HPkk3JgI&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=TeDcLjOOiK4&t=1041s&ab_channel=Fraz
//* https://www.youtube.com/watch?v=dbRJFnQoKTI&ab_channel=Fraz

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method

        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }

        node *dummy = new node(-1);
        dummy->next = head;
        node *pre = dummy, *curr = dummy;
        int count = 0;

        while (curr->next != NULL)
        {
            curr = curr->next;
            count++;
        }

        node *nex;
        while (count >= k)
        {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < k; ++i)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }

        if (count > 0)
        {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < count; ++i)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
        }

        return dummy->next;
    }
};

//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends