//* https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
//* https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1

//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string sequence(map<char,string> mp, char ch){
    if(mp.find(ch) != mp.end()){
        return mp[ch];
    }
    
    char ptr;
    for(auto& m : mp){
        if(ch < m.first){
            break;
        }
        ptr = m.first;
    }
    string number = mp[ptr];
    int times = (ch - ptr) + 1;
    string temp = "";
    for(int i = 1; i <= times; i++){
        temp += number;
    }
    return temp;
}

string printSequence(string s)
{
    //code here.
    
    string answer="";
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    map<char,string> mp;
    mp['A'] = "2";
    mp['D'] = "3";
    mp['G'] = "4";
    mp['J'] = "5";
    mp['M'] = "6";
    mp['P'] = "7";
    mp['T'] = "8";
    mp['W'] = "9";

    for(char ch : s){
        if(ch == ' '){
            answer += '0';
        }
        else{
            answer += sequence(mp, ch);
        }
    }

    return answer;
}