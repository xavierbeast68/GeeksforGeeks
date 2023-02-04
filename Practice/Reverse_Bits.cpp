/**
 ** URL : https://practice.geeksforgeeks.org/problems/reverse-bits3556/1
 */

// https://www.geeksforgeeks.org/program-decimal-binary-conversion/
// https://www.geeksforgeeks.org/program-binary-decimal-conversion/
// https://www.geeksforgeeks.org/stdstoi-function-in-cpp/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long X=1;
    string s=bitset<32>(X).to_string();  // converts X to binary form and then store it in string
    reverse(s.begin(),s.end()); // reverses the binary string
    long long rev=stoll(s,nullptr,2);   // using stoi will cause overflow
    cout<<rev<<endl;
}
