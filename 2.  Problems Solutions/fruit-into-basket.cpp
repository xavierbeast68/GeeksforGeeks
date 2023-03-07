//* https://www.geeksforgeeks.org/maximum-no-of-apples-that-can-be-kept-in-a-single-basket/
//* https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1?problemStatus=unsolved&page=1&sortBy=newest&query=problemStatusunsolvedpage1sortBynewest
//* https://leetcode.com/problems/fruit-into-baskets/description/
//* https://leetcode.com/problems/fruit-into-baskets/submissions/893188024/
//* https://www.youtube.com/watch?v=yYtaV0G3mWQ

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int currFruitsInBasket(map<int, int> &mp)
    {
        return (accumulate(begin(mp), end(mp), 0,
                           [](int value, const map<int, int>::value_type &p)
                           { return value + p.second; }));
    }

    int totalFruits(int N, vector<int> &fruits)
    {
        map<int, int> mp;
        mp[fruits[0]]++;
        int currElement = fruits[0], currIndex = 0;
        int i = 1;

        int maxFruits = currFruitsInBasket(mp);

        while (i < N)
        {
            if (fruits[i] == fruits[i - 1])
            {
                mp[fruits[i]]++;
                int fruitsInBasket = currFruitsInBasket(mp);
                maxFruits = max(maxFruits, fruitsInBasket);
            }

            else
            {
                if (mp.size() < 2 || mp.find(fruits[i]) != mp.end())
                {
                    mp[fruits[i]]++;

                    int fruitsInBasket = currFruitsInBasket(mp);
                    maxFruits = max(maxFruits, fruitsInBasket);
                    currElement = fruits[i];
                    currIndex = i;
                }

                else
                {
                    mp.clear();
                    mp[currElement] = i - currIndex;

                    mp[fruits[i]]++;
                    int fruitsInBasket = currFruitsInBasket(mp);
                    maxFruits = max(maxFruits, fruitsInBasket);
                    currElement = fruits[i];
                    currIndex = i;
                }
            }
            i++;
        }

        return maxFruits;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++)
            cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends