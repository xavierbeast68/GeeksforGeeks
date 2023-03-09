//* https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/reverse-a-linked-list/
//* https://www.youtube.com/watch?v=iRtLEoL-r-g&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=t7YaoQOFXzk&ab_channel=ApnaCollege

//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }

}

class GFG {
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {

            int n = sc.nextInt();

            Node head = new Node(sc.nextInt());
            Node tail = head;

            for (int i = 0; i < n - 1; i++) {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }

            Solution ob = new Solution();
            head = ob.reverseList(head);
            printList(head);
            t--;
        }
    }
}

// } Driver Code Ends

// function Template for Java

/*
 * linked list node class:
 * 
 * class Node {
 * int data;
 * Node next;
 * Node(int value) {
 * this.value = value;
 * }
 * }
 * 
 */

class Solution {
    // Function to reverse a linked list.
    Node reverseList(Node head) {
        // code here

        if (head == null || head.next == null) {
            return head;
        }

        Node prev, curr, Next;
        prev = null;
        curr = head;

        while (curr != null) {
            Next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = Next;
        }

        head = prev;
        return head;
    }
}
