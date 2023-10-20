#User function Template for python3

class Solution:
    def getMinDiff(self, arr, n, k):
        # code here
        arr.sort()
        diff = arr[n-1]-arr[0]
        for i in range(1,n):
            if(arr[i]-k<0):
                continue
            mini = min(arr[0]+k,arr[i]-k)
            maxi = max(arr[i-1]+k,arr[n-1]-k)
            diff = min(diff,maxi-mini)
        result = diff
        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends