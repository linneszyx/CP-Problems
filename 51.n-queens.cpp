/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (63.52%)
 * Likes:    9182
 * Dislikes: 207
 * Total Accepted:    506.6K
 * Total Submissions: 796.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solv;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nqueen(board,0);
        return solv;
    }
    bool checksafe(vector<string> &board,int r,int c){
        int n = size(board);
        for (int i = 0; i < n; i++)
        {
            if(board[i][c]=='Q') return false;
            if(r-i>=0 and c-i>=0 and board[r-i][c-i]=='Q'){
                return false;
            }
            if(r-i>=0 and c+i<=n and board[r-i][c+i]=='Q'){
                return false;
            }
        }
        return true;
        
    }
    void nqueen(vector<string>&board,int r){
        if(r==size(board)){
            solv.push_back(board);
            return;
        }
        for (int c = 0; c < size(board); c++)
        {
            if(checksafe(board,r,c)){
                board[r][c]='Q';
                nqueen(board,r+1);
                board[r][c]='.';
            }
        }
        
    }
};
// @lc code=end

