#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;}   // vector<ll> arr = readvector(n);


//* Time Complexity-> O(n*log(n))
int sliding_window_approach(vector<int> arr, int n, int m){
    int minDiff = INT_MAX;

    sort(begin(arr), end(arr));

    for (int i = 0; i < n-(m-1); i++)
    {
        int maxPacket = arr[i+(m-1)];
        int minPacket = arr[i];

        minDiff = min(minDiff, maxPacket-minPacket);
    }
    return minDiff;
}

//* Time Complexity-> O(2^n) using subset sums
int brute_force(vector<int> arr, int n, int m){
    int minDiff = INT_MAX;

    //* https://www.geeksforgeeks.org/print-sums-subsets-given-set/

    return minDiff;
}

signed main(){
    cout << "Enter number of chocolate packets" << endl;
    int n; cin>>n;
    cout << "Enter chocolate packets sizes" << endl;
    vector<int> arr = readvector(n);
    cout << "Enter number of students" << endl;
    int m; cin>>m;

    // int ans = brute_force(arr, n, m); // or naive approach
    // cout << ans << endl;

    int ans = sliding_window_approach(arr, n, m);
    cout << ans << endl;
}