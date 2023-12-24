class Solution {
public:
    // Function to calculate the minimum number of operations required to make alternate characters in the string
    int minOperations(string s) {
        int start0 = 0; // Initialize the count of '1's at even positions
        
        // Traverse through the string
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) { // If the index is even
                if (s[i] == '1') {
                    start0++; // Increment count of '1's at even positions if '1' is encountered
                }
            } else { // If the index is odd
                if (s[i] == '0') {
                    start0++; // Increment count of '1's at odd positions if '0' is encountered
                }
            }
        }
        
        // Return the minimum count of '1's or '0's required to make characters alternate
        return min(start0, (int) s.size() - start0);
    }
};



