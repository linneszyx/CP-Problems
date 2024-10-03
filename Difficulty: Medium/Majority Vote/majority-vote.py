class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, nums):
        #Your Code goes here.
        c = {}
        for i in nums:
            if i in c.keys():
                c[i]+=1
            else:
                c[i]=1
        maxi = len(nums)/3
        result = []
        for key,value in c.items():
            if value>maxi:
                result.append(key)
        if result:
            return result
        else:
            return [-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.findMajority(nums)
        print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends