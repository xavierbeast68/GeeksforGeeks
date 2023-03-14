// https://leetcode.com/problems/merge-k-sorted-lists/description/
// https://leetcode.com/problems/merge-k-sorted-lists/editorial/
// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/library/merge-k-sorted-linked-lists
// https://www.interviewbit.com/problems/merge-k-sorted-lists/
// https://www.youtube.com/watch?v=7wdont5Bgnk
// https://www.youtube.com/watch?v=RYJ3vs8qx10
// https://www.youtube.com/watch?v=q5a5OiGbT6Q



//{ Driver Code Starts
    import java.util.*;

    class Node
    {
        int data;
        Node next;
        
        Node(int key)
        {
            data = key;
            next = null;
        }
    }
    
    
    class GfG
    {
        public static void printList(Node node)
        {
            while(node != null)
            {
                System.out.print(node.data + " ");
                node = node.next;
            }
        }
        
        public static void main (String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int t = sc.nextInt();
            while(t-- > 0)
            {   
                int N = sc.nextInt();
                
                Node []a = new Node[N];
                
                for(int i = 0; i < N; i++)
                {
                    int n = sc.nextInt();
                    
                    Node head = new Node(sc.nextInt());
                    Node tail = head;
                    
                    for(int j=0; j<n-1; j++)
                    {
                        tail.next = new Node(sc.nextInt());
                        tail = tail.next;
                    }
                    
                    a[i] = head;
                }
                
                Solution g = new Solution();
                 
                Node res = g.mergeKList(a,N);
                if(res!=null)
                    printList(res);
                System.out.println();
            }
        }
    }
    // } Driver Code Ends
    
    
    /*class Node
    {
        int data;
        Node next;
        
        Node(int key)
        {
            data = key;
            next = null;
        }
    }
    */
    
    // a is an array of Nodes of the heads of linked lists
    // and N is size of array a
    
    
    class Solution
    {
        //Function to merge K sorted linked list.
        Node mergeKList(Node[] lists,int k)
        {
            //Add your code here.
            
            PriorityQueue<Node> queue = new PriorityQueue<>(new NodeComparator());
            Node mergedLL = new Node(-1);
            Node tail = mergedLL;
    
            for (int i = 0; i < k; i++) {
                if (lists[i] != null) {
                    queue.add(lists[i]);
                }
            }
    
            if (queue.isEmpty()){
                return null;
            }
    
            while (!queue.isEmpty()) {
                Node temp = queue.poll();
    
                tail.next = temp;
                tail = tail.next;
    
                if (temp.next != null) {
                    queue.add(temp.next);
                }
            }
    
    
            return mergedLL.next;
        }
        class NodeComparator implements Comparator<Node> {
            public int compare(Node a, Node b)
            {
                if (a.data > b.data)
                    return 1;
                else if (a.data < b.data)
                    return -1;
                return 0;
            }
        }
    }
    