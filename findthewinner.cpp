#include <bits/stdc++.h> 
string getWinner(vector < string > & votes) {
    // Write your code here.
    unordered_map < string, int > m;    
    int max = 0;
    string winner;
    for (auto i: votes) {
        m[i]++;
        if (m[i] > max) {
            max = m[i];
            winner = i;
        }
        else if (m[i] == max) {
            if (i < winner) {
                winner = i;
            }
        }
    }
    return winner;
}