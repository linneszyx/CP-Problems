//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int mergeSort(long long arr[], long long N)
    {
        long long t[N];
        return merge(arr, t, 0, N - 1);
    }
    long long int merge(long long arr[], long long t[], int l, int r)
    {
        long long mid, count = 0;
        if (r > l)
        {
            mid = (r + l) / 2;
            count += merge(arr, t, l, mid);
            count += merge(arr, t, mid + 1, r);
            count += merge1(arr, t, l, mid + 1, r);
        }
        return count;
    }
    long long int merge1(long long arr[],long long t[],int l,long long mid,int r){
        int i,j,k;
        long long int c=0;
        i = l;
        j = mid;
        k = l;
         while ((i <= mid - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            t[k++] = arr[i++];
        }
        else {
            t[k++] = arr[j++];
            c = c + (mid - i);
        }
    }
    while (i <= mid - 1)
        t[k++] = arr[i++];
    while (j <= r)
        t[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = t[i];
 
    return c;

    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long res = mergeSort(arr,N);
    }
};

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends