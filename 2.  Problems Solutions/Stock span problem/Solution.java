//* https://leetcode.com/problems/online-stock-span/
//* https://www.geeksforgeeks.org/the-stock-span-problem/
//* https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
//* https://www.interviewbit.com/blog/stock-span-problem/
//* https://www.youtube.com/watch?v=p9T-fE1g1pU&ab_channel=AdityaVerma

//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int a[] = new int[n];

            int i = 0;
            for (i = 0; i < n; i++)
                a[i] = sc.nextInt();

            int[] s = new Solution().calculateSpan(a, n);

            for (i = 0; i < n; i++) {
                System.out.print(s[i] + " ");
            }

            System.out.println();
        }
    }

}
// } Driver Code Ends

class Solution {
    public static void stockSpan(int[] stocks, int[] span, int n) {
        Stack<Integer> s = new Stack<>();
        span[0] = 1;
        s.push(0);

        for (int i = 0; i < n; ++i) {
            int currPrice = stocks[i];
            while (!(s.isEmpty()) && currPrice >= stocks[s.peek()]) {
                s.pop();
            }
            if (s.isEmpty()) {
                span[i] = i + 1;
            } else {
                int prevHigh = s.peek();
                span[i] = i - prevHigh;
            }
            s.push(i);
        }
    }

    // Function to calculate the span of stockâ€™s price for all n days.
    public static int[] calculateSpan(int price[], int n) {
        // Your code here

        int span[] = new int[n];

        stockSpan(price, span, n);

        return span;
    }

}