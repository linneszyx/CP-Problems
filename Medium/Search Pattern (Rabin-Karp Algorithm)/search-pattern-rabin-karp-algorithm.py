#User function Template for python3

class Solution:
    def search(self, pattern, text):
        # code here
        ans = []
        a = len(pattern)
        b = len(text)
        for i in range(b-a+1):
            j=0
            while j<a:
                if text[i+j]!=pattern[j]:
                    break
                j+=1
            if j==a:
                ans.append(i+1)
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends