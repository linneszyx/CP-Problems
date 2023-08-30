#User function Template for python3


class Solution:
    def maxSum (self, w, x, b, n):
        #code here
        disc = {}
        for i in range(n):
            disc[x[i]] = b[i]
        cs = 0
        mx = float('-inf')
        ms = 0
        me = 0
        s=0
        for i in range(len(w)):
            if w[i] in disc:
                cs+=disc[w[i]]
            else:
                cs+=ord(w[i])
            mx = max(mx,cs)
            if mx<=cs:
                ms = s
                me = i
                mx = cs
            if cs<0:
                cs = 0
                s=i+1
        return w[ms:me+1]
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        w = input()
        n = int(input())
        x = input().split(' ')
        b = input().split(' ')
        for itr in range(n):
            b[itr] = int(b[itr])
       

        ob = Solution()
        print(ob.maxSum(w,x,b,n))
# } Driver Code Ends