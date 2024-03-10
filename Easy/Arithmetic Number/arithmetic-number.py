#User function Template for python3

class Solution:
    def inSequence(self, A, B, C):
        # code here
        if B < A and C > 0:
            return 0
        elif A == B and C == 0:
            return 1
        elif A != B and C == 0:
            return 0
        elif A < B and C < 0:
            return 0
        n = ((B-A)/C)+1
        if n.is_integer():
            return 1
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A, B, C = [int(x) for x in input().split()]
        
        ob = Solution();
        print(ob.inSequence(A, B, C))
# } Driver Code Ends