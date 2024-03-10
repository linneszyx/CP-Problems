#User function Template for python3
class Solution:
	def countPairs(self, mat1, mat2, n, x):
		# code here
		from bisect import bisect_left
		ans  = 0
		for r in mat1:
		    for y in r:
		        e=x-y
		        lo,hi=0,n
		        while lo<hi:
		            mi = lo+(hi-lo)//2
		            if mat2[mi][0]>e:
		                hi=mi
		            else:
		                lo=mi+1
		        if lo-1>=0:
		            i = bisect_left(mat2[lo-1],e)
		            if i<n and mat2[lo-1][i]==e:
		                ans+=1
		return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n , x = input().split()
		n,x = int(n), int(x)
		mat1 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat1.append(a)

		mat2 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat2.append(a)

		ob = Solution()
		ans = ob.countPairs(mat1, mat2, n, x)
		print(ans)

# } Driver Code Ends