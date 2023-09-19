#User function Template for python3

class Solution:
    def MedianOfArrays(self, array1, array2):
                arr=array1+array2
                arr.sort()
              
                n=len(arr)
                if n%2==1:
                    return arr[n//2]
                else:
                    m1=arr[n//2-1]
                    m2=arr[n//2]
                    m=(m1+m2)/2
                    
                    
                    if m%1!=0:
                        return m
                    else:
                        
                        return int(m)


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    tcs=int(input())

    for _ in range(tcs):
        m = input()
        arr1=[int(x) for x in input().split()]
        n = input()
        arr2=[int(x) for x in input().split()]
        
        
        ob = Solution()
        print(ob.MedianOfArrays(arr1,arr2))

# } Driver Code Ends