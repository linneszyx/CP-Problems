class Solution {
public:
    int maxScore(string inputStr) {
        int onesCount = count(inputStr.begin(), inputStr.end(), '1');
        
        int result = 0;
        int zerosCount = 0;
        for (int i = 0; i < inputStr.size() - 1; i++) {
            if (inputStr[i] == '1') {
                onesCount--;
            } else {
                zerosCount++;
            }
            
            result = max(result, zerosCount + onesCount);
        }
        
        return result;
    }
};