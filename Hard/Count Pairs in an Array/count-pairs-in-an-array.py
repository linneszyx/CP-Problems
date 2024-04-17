#User function Template for python3

from sortedcontainers import SortedList

class Solution:    
    def countPairs(self,arr, n): 
         # Your code goes here
        
        A = [i*v for i,v in enumerate(arr)]
        S = SortedList()
        ans = 0
        while A:
             v = A.pop()
             ix = S.bisect_left(v)
             ans+=ix
             S.add(v)
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob= Solution()
        print(ob.countPairs(a, n))

        T -= 1


if __name__ == "__main__":
    main()
    
# } Driver Code Ends