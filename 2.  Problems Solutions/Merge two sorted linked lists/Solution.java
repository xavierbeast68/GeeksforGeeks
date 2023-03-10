//* https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
//* https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

class MergeLists {
    Node head;

    /* Function to print linked list */
    public static void printList(Node head) {

        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
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
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            Node head1 = new Node(sc.nextInt());
            Node tail1 = head1;
            for (int i = 0; i < n1 - 1; i++) {
                tail1.next = new Node(sc.nextInt());
                tail1 = tail1.next;
            }
            Node head2 = new Node(sc.nextInt());
            Node tail2 = head2;
            for (int i = 0; i < n2 - 1; i++) {
                tail2.next = new Node(sc.nextInt());
                tail2 = tail2.next;
            }

            LinkedList obj = new LinkedList();
            Node head = obj.sortedMerge(head1, head2);
            printList(head);

            t--;

        }
    }
}

// } Driver Code Ends

/*
 * Merge two linked lists
 * head pointer input could be NULL as well for empty list
 * Node is defined as
 * class Node
 * {
 * int data;
 * Node next;
 * Node(int d) {data = d; next = null; }
 * }
 */

class LinkedList {
    // Function to merge two sorted linked list.
    Node sortedMerge(Node list1, Node list2) {
        // This is a "method-only" submission.
        // You only need to complete this method

        Node mergedLL = new Node(-1);
        Node temp = mergedLL;

        while (list1 != null && list2 != null) {
            if (list1.data <= list2.data) {
                // ListNode tempo = new ListNode(list1.val);
                // temp.next = tempo;
                temp.next = new Node(list1.data);
                temp = temp.next;
                list1 = list1.next;
            } else {
                // ListNode tempo = new ListNode(list2.val);
                // temp.next = tempo;
                temp.next = new Node(list2.data);
                temp = temp.next;
                list2 = list2.next;
            }
        }

        while (list1 != null) {
            // ListNode tempo = new ListNode(list1.val);
            // temp.next = tempo;
            temp.next = new Node(list1.data);
            temp = temp.next;
            list1 = list1.next;
        }
        while (list2 != null) {
            // ListNode tempo = new ListNode(list2.val);
            // temp.next = tempo;
            temp.next = new Node(list2.data);
            temp = temp.next;
            list2 = list2.next;
        }

        return mergedLL.next;
    }
}
