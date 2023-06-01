long long connectRopes(int* arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    long long cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}
