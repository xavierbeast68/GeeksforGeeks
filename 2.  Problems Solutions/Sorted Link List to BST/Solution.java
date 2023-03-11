//* https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
//* https://www.youtube.com/watch?v=mbEaJWHtTvQ
//* https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
//* https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.codingninjas.com/codestudio/library/convert-a-sorted-linked-list-to-balanced-bst
//* https://www.codingninjas.com/codestudio/problems/sorted-linked-list-to-balanced-bst_842564

//{ Driver Code Starts
import java.util.*;

class LNode {
    int data;
    LNode next;

    LNode(int d) {
        data = d;
        next = null;
    }
}

class TNode {
    int data;
    TNode left, right;

    TNode(int x) {
        data = x;
        left = right = null;
    }

}

class ListToBST {

    /* Function to print linked list */
    public static void preOrder(TNode root) {

        if (root == null)
            return;

        System.out.print(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    /* Driver program to test above functions */
    public static void main(String args[]) {

        /*
         * Constructed Linked List is 1->2->3->4->5->6->
         * 7->8->8->9->null
         */
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {
            int n = sc.nextInt();
            LNode head = new LNode(sc.nextInt());
            LNode tail = head;
            for (int i = 0; i < n - 1; i++) {
                tail.next = new LNode(sc.nextInt());
                tail = tail.next;
            }

            Solution obj = new Solution();
            TNode root = obj.sortedListToBST(head);
            preOrder(root);

            System.out.println();

            t--;

        }
    }
}

// } Driver Code Ends

// User function Template for Java

/*
 * Linked List Node
 * class LNode
 * {
 * int data;
 * LNode next;
 * LNode(int d) {
 * data = d;
 * next = null;
 * }
 * }
 * 
 * //Tree Node
 * class TNode
 * {
 * int data;
 * TNode left, right;
 * TNode(int x)
 * {
 * data=x;
 * left=right=null;
 * }
 * 
 * }
 */

class Solution {
    public TNode bst(int low, int high, ArrayList<Integer> arr) {
        if (low > high) {
            return null;
        }

        int mid = low + (high - low) / 2;
        if ((high - low + 1) % 2 == 0) {
            mid += 1;
        }

        TNode root = new TNode(arr.get(mid));
        root.left = bst(low, mid - 1, arr);
        root.right = bst(mid + 1, high, arr);

        return root;
    }

    public TNode sortedListToBST(LNode head) {
        // code here

        ArrayList<Integer> arr = new ArrayList<>();

        while (head != null) {
            arr.add(head.data);
            head = head.next;
        }

        int low = 0, high = arr.size() - 1;
        return bst(low, high, arr);
    }
}
