//* https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
//* https://www.youtube.com/watch?v=mbEaJWHtTvQ
//* https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
//* https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.codingninjas.com/codestudio/library/convert-a-sorted-linked-list-to-balanced-bst
//* https://www.codingninjas.com/codestudio/problems/sorted-linked-list-to-balanced-bst_842564

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode *next;

    LNode(int x)
    {
        data = x;
        next = NULL;
    }
};

struct TNode
{

    int data;
    struct TNode *left;
    struct TNode *right;
    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

/*
//Linked List
struct LNode
{
    int data;
    struct LNode* next;

    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode
{

    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution
{
public:
    TNode *bst(int low, int high, vector<int> &arr)
    {
        if (low > high)
        {
            return NULL;
        }

        int mid = low + (high - low) / 2;
        if ((high - low + 1) % 2 == 0)
        {
            mid += 1;
        }

        TNode *root = new TNode(arr[mid]);
        root->left = bst(low, mid - 1, arr);
        root->right = bst(mid + 1, high, arr);

        return root;
    }
    TNode *sortedListToBST(LNode *head)
    {
        // code here

        vector<int> arr;

        while (head != NULL)
        {
            arr.push_back(head->data);
            head = head->next;
        }

        int low = 0, high = arr.size() - 1;
        return bst(low, high, arr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode *Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends