//* https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class Driverclass {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while (n-- > 1) {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }

            head = new Solution().mergeSort(head);
            printList(head);
            System.out.println();
        }
    }

    public static void printList(Node head) {
        if (head == null)
            return;

        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

// } Driver Code Ends

// User function Template for Java
/*
 * class Node
 * {
 * int data;
 * Node next;
 * Node(int key)
 * {
 * this.data = key;
 * next = null;
 * }
 * }
 */

class Solution {
    // Function to sort the given linked list using Merge Sort.
    static Node mergeSort(Node head) {
        // add your code here

        if (head == null || head.next == null) {
            return head;
        }

        Node midNode = calMid(head);

        Node newRight = mergeSort(midNode.next);
        midNode.next = null;
        Node newLeft = mergeSort(head);

        return merge(newLeft, newRight);
    }

    public static Node calMid(Node head) {
        Node slow = head;
        Node fast = head.next;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        return slow;
    }

    public static Node merge(Node l1, Node l2) {
        Node mergedLL = new Node(-1);
        Node temp = mergedLL;

        while (l1 != null && l2 != null) {
            if (l1.data <= l2.data) {
                temp.next = l1;
                temp = temp.next;
                l1 = l1.next;
            } else {
                temp.next = l2;
                temp = temp.next;
                l2 = l2.next;
            }
        }

        while (l1 != null) {
            temp.next = l1;
            temp = temp.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            temp.next = l2;
            temp = temp.next;
            l2 = l2.next;
        }

        return mergedLL.next;
    }
}
