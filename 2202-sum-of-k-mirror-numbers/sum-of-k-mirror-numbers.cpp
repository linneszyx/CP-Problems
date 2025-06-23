class Solution {
public:
    static inline int req;
    static inline long long res;
    static inline int numarr[1000000];
    static inline int sizearr[1000000];
    static inline bool ff(long long x, int k) {
        long long buf[64];
        int t = 0;
        while (x) {
            buf[t++] = x % k;
            x /= k;
        }
        for (int a = 0, b = t - 1; a < b; ++a, --b)
            if (buf[a] != buf[b])
                return false;
        return true;
    }
    static long long kMirror(int k, int n) {
        req = n;
        res = 0;
        numarr[0] = 1;
        sizearr[0] = 1;
        int idx = 1;
        while (req > 0) {
            int num = numarr[--idx];
            int size = sizearr[idx];
            int arr[20];
            int tmp = num;
            int len = 0;
            while (tmp) {
                len++;
                tmp /= 10;
            }
            tmp = num;
            int i = len - 1;
            int mid = i;
            int j = size - 1;
            bool allnine = true;
            for (; i >= 0; --i) {
                int d = tmp % 10;
                arr[i] = d;
                if (d != 9)
                    allnine = false;
                tmp /= 10;
            }
            for (i = 0; j > mid;)
                arr[j--] = arr[i++];
            long long number = 0;
            for (int p = 0; p < size; ++p)
                number = number * 10 + arr[p];
            if (ff(number, k)) {
                res += number;
                if (--req == 0)
                    break;
            }
            if (allnine) {
                int nextsize = size + 1;
                int nextnum = (size & 1) ? ((num + 1) / 10) : (num + 1);
                numarr[idx] = nextnum;
                sizearr[idx] = nextsize;
            } else {
                numarr[idx] = num + 1;
                sizearr[idx] = size;
            }
            ++idx;
        }
        return res;
    }
};