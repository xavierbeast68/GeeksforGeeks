//* https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    Node *calMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node *merge(Node *l1, Node *l2)
    {
        Node *mergedLL = new Node(-1);
        Node *temp = mergedLL;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->data <= l2->data)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        while (l1 != NULL)
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }

        return mergedLL->next;
    }

    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // your code here

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *midNode = calMid(head);

        Node *newRight = mergeSort(midNode->next);
        midNode->next = NULL;
        Node *newLeft = mergeSort(head);

        return merge(newLeft, newRight);
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends