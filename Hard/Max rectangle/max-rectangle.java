//{ Driver Code Starts
import java.util.*;

class FindMinCost
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			int arr[][] = new int[n][m];
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++ )
				{
					arr[i][j] = sc.nextInt();
				}
			}
			System.out.println(new Solution().maxArea(arr, n, m));
		t--;
		}
	}
}
// } Driver Code Ends


/*Complete the function given below*/
class Solution {
    ArrayList<Integer> nextSmallerElements(int[] heights) {

        // create stack 
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        // create ans 
        ArrayList<Integer> ans = new ArrayList<>();

        // loop on heights from right to left 
        for(int i = heights.length - 1 ; i >= 0 ; i--) {

            // get current index value 
            int cur = heights[i];

            while( stack.peek() != -1 && heights[stack.peek()] >= cur ) 
                stack.pop();

            ans.add(0, stack.peek());

            // push index 
            stack.push(i);

        }
        // Collections.reverse(ans);
        return ans;
    }

 ArrayList<Integer> prevSmallerElements(int[] heights) {

        // create stack 
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        // create ans 
        ArrayList<Integer> ans = new ArrayList<>();

        // loop on heights from left to right 
        for(int i = 0 ; i < heights.length ; i++) {


            // get current index value 
            int cur = heights[i];

            while( stack.peek() != -1 && heights[stack.peek()] >= cur ) 
                stack.pop();

            ans.add(stack.peek());

            // push index 
            stack.push(i);

        }
        return ans;
    }

public int largestRectangleArea(int[] heights) {
        
        // get all next smaller elements 
        ArrayList<Integer> next = nextSmallerElements(heights);

        // get all prev smaller elements 
        ArrayList<Integer> prev = prevSmallerElements(heights);

        int area = 0;

        // iterate through next and prev elements 
        for(int i = 0 ; i < next.size() ; i++) {

            // get Length 
            int length = heights[i];

            // one check 
            if(next.get(i) == -1) 
                next.set(i , heights.length);

            // get breath 
            int breath = next.get(i) - prev.get(i) - 1;

            // area 
            area = Math.max( (length * breath)  , area );
        }

        return area;
    }
    
    public int maxArea(int M[][], int n, int m) {
        
        // get area of first row 
        int area = largestRectangleArea(M[0]);
        
        // repeat following statements for remaining rows
        for(int i = 1 ; i < M.length ; i++) {
            for(int j = 0 ; j < M[i].length ; j++) {
                
                // update row - add previous row's values in current row's value
                if(M[i][j] != 0) 
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
                
            }
            
            int newArea = largestRectangleArea(M[i]);
            area = Math.max(area , newArea);
        }
        
        return area;
    }
}