/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 *
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (80.60%)
 * Likes:    2792
 * Dislikes: 216
 * Total Accepted:    345.5K
 * Total Submissions: 428.4K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * Given an n x n binary matrix image, flip the image horizontally, then invert
 * it, and return the resulting image.
 * 
 * To flip an image horizontally means that each row of the image is
 * reversed.
 * 
 * 
 * For example, flipping [1,1,0] horizontally results in [0,1,1].
 * 
 * 
 * To invert an image means that each 0 is replaced by 1, and each 1 is
 * replaced by 0.
 * 
 * 
 * For example, inverting [0,1,1] results in [1,0,0].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: image = [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row:
 * [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == image.length
 * n == image[i].length
 * 1 <= n <= 20
 * images[i][j] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
       int row =image.size();
        int col = image[0].size();
        int i,j;
        for(i=0;i<row;i++){
            int s=0;
            int e = col-1;
            while(s<e){
                swap(image[i][s],image[i][e]);
                s++;
                e--;
            }
        }
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(image[i][j]==0){
                    image[i][j]=1;
                }
                else{
                    image[i][j]=0;
                }
            }
        }
        return image;  
    }
};
// @lc code=end

