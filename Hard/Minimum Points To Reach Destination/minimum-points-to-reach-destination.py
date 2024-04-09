#User function Template for python3
class Solution:
	def minPoints(self, m, n, points):
		# code here
		dp = [[0]*n for _ in range(m)]
		for i in range(m-1,-1,-1):
		    for j in range(n-1,-1,-1):
    		    if i==m-1 and j==n-1:
    		        dp[i][j] = max(1,1-points[i][j])
    		    elif i==m-1:
    		        dp[i][j] = max(1,dp[i][j+1]-points[i][j])
    		    elif j==n-1:
    		        dp[i][j] = max(1,dp[i+1][j]-points[i][j])
    		    else:
    		        dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-points[i][j])
        return dp[0][0]
 

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		m,n = input().split()
		m,n = int(m),int(n)
		points = []
		for _ in range(m):
			temp = [int(x) for x in input().split()]
			points.append(temp)
		ob = Solution()
		ans = ob.minPoints(m,n,points)
		print(ans)




# } Driver Code Ends