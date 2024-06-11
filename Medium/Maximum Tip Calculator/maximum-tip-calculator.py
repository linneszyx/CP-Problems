
from typing import List


class Solution:
    def maxTip(self, n : int, x : int, y : int, arr : List[int], brr : List[int]) -> int:
        # code here
        tp = zip(arr,brr)
        st = sorted(tp,key=lambda t:abs(t[0]-t[1]),reverse=True)
        cntA,cntB,total = 0,0,0
        for a,b in st:
            if(a>=b and cntA<x) or cntB==y:
                total+=a
                cntA+=1
            else:
                total+=b
                cntB+=1
        return total
        



#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        x = int(input())

        y = int(input())

        arr = IntArray().Input(n)

        brr = IntArray().Input(n)

        obj = Solution()
        res = obj.maxTip(n, x, y, arr, brr)

        print(res)

# } Driver Code Ends