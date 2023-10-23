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


string printSequence(string S)
{
  string result = "";
    for(int i=0; i<S.length(); i++) {
        switch(S[i]) {
            case 'C': result += "2";
            case 'B': result += "2";
            case 'A': result += "2";
                        break;
            case 'F': result += "3";
            case 'E': result += "3";
            case 'D': result += "3";
                        break;
            case 'I': result += "4";
            case 'H': result += "4";
            case 'G': result += "4";
                        break;
            case 'L': result += "5";
            case 'K': result += "5";
            case 'J': result += "5";
                        break;
            case 'O': result += "6";
            case 'N': result += "6";
            case 'M': result += "6";
                        break;
            case 'S': result += "7";
            case 'R': result += "7";
            case 'Q': result += "7";
            case 'P': result += "7";
                        break;
            case 'V': result += "8";
            case 'U': result += "8";
            case 'T': result += "8";
                        break;
            case 'Z': result += "9";
            case 'Y': result += "9";
            case 'X': result += "9";
            case 'W': result += "9";
                        break;
            default: result += "0";
        }
    }
    
    return result;
}