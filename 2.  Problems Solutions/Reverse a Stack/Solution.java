//* https://practice.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        // taking testcases
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String str = br.readLine();

            // input n and d
            int n = Integer.parseInt(str);
            Stack<Integer> stack = new Stack<>();
            String str1 = br.readLine();
            String[] starr1 = str1.split(" ");
            // inserting elements in the array
            for (int j = 0; j < n; j++) {
                stack.push(Integer.parseInt(starr1[j]));
            }
            // calling reverse() function
            Solution.reverse(stack);
            for (int j : stack) {
                out.print(j + " ");
            }
            out.println();
        }
        out.close();
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    public static void pushAtBottom(Stack<Integer> s, int data) {
        if (s.isEmpty()) { // s.size() == 0
            s.push(data);
            return;
        }

        int top = s.pop();
        pushAtBottom(s, data);
        s.push(top);
    }

    static void reverse(Stack<Integer> s) {
        // add your code here
        if (s.isEmpty()) { // s.size() == 0
            return;
        }

        int top = s.pop();
        reverse(s);
        pushAtBottom(s, top);
    }
}