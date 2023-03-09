//* https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
//* https://leetcode.com/problems/palindrome-linked-list/editorial/

//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Is_LinkedList_Palindrom {
    Node head;
    Node tail;

    /* Function to print linked list */
    void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /* Inserts a new Node at front of the list. */
    public void addToTheLast(Node node) {

        if (head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {
            int n = sc.nextInt();
            // int k = sc.nextInt();
            Is_LinkedList_Palindrom llist = new Is_LinkedList_Palindrom();
            // int n=Integer.parseInt(br.readLine());
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;
            for (int i = 1; i < n; i++) {
                int a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }

            Solution g = new Solution();
            if (g.isPalindrome(head) == true)
                System.out.println(1);
            else
                System.out.println(0);
            t--;
        }

    }
}

// } Driver Code Ends

/*
 * Structure of class Node is
 * class Node
 * {
 * int data;
 * Node next;
 * 
 * Node(int d)
 * {
 * data = d;
 * next = null;
 * }
 * }
 */

class Solution {
    // slow-fast technique or two-runners pointer technique
    Node findMid(Node head) {
        Node slow, fast;
        slow = fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    Node reverseList(Node midNode) {
        Node prev = null;
        Node curr = midNode;
        Node Next;

        while (curr != null) {
            Next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    // Function to check whether the list is palindrome.
    boolean isPalindrome(Node head) {
        // Your code here
        if (head.next == null) {
            return true;
        }

        Node midNode = findMid(head);

        Node left = head;
        Node right = reverseList(midNode);

        while (right != null) {
            if (left.data != right.data) {
                return false;
            }

            left = left.next;
            right = right.next;
        }

        return true;
    }
}
