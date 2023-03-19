//* https://practice.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

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

        while (t-- > 0) {
            int n = sc.nextInt();

            Node head = new Node(sc.nextInt());
            Node tail = head;
            for (int i = 0; i < n - 1; i++) {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }

            Solution g = new Solution();
            printList(g.zigZag(head));
        }
    }
}

// } Driver Code Ends

/*
 * Node is as follows:
 * 
 * class Node {
 * int data;
 * Node next;
 * Node(int d) {
 * data = d;
 * next = null;
 * }
 * }
 * 
 */

class Solution {
    public static Node zigZag(Node head) {
        // add code here.

        boolean flag = true;
        Node curr = head;
        while (curr.next != null) {
            if (flag) {
                if (curr.data > curr.next.data) {
                    int data = curr.data;
                    curr.data = curr.next.data;
                    curr.next.data = data;
                }
            } else {
                if (curr.data < curr.next.data) {
                    int data = curr.data;
                    curr.data = curr.next.data;
                    curr.next.data = data;
                }
            }

            curr = curr.next;
            flag = !flag;
        }
        return head;
    }
}