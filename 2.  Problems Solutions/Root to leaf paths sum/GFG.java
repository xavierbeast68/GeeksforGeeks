//* https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/
//* https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
//* https://www.youtube.com/watch?v=J0k0xLA8k8c
//* https://www.youtube.com/watch?v=Jk16lZGFWxE

//{ Driver Code Starts
//Contributed by Sudarshan Sharma
import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void printInorder(Node root) {
        if (root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Tree1 g = new Tree1();
            System.out.println(g.treePathsSum(root));
            // System.out.println();
        }
    }
}

// } Driver Code Ends

/*
 * Complete the function below.
 * Node is as follows:
 * class Tree
 * {
 * int data;
 * Tree left,right;
 * Tree(int d){
 * data=d;
 * left=null;
 * right=null;
 * }
 * }
 */
class Tree1 {
    public static long dfs(Node root, long sum) {
        if (root == null) {
            return 0;
        }

        sum = sum * 10 + root.data;

        if (root.left == null && root.right == null) {
            return sum;
        }

        return dfs(root.left, sum) + dfs(root.right, sum);
    }

    public static long treePathsSum(Node root) {
        // add code here.
        return dfs(root, 0);
    }
}