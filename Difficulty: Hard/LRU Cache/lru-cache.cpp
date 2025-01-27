//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#define pi pair<int,int>
class LRUCache {
  private:
  int cap;
    list<pi> ch;
    unordered_map<int,list<pi>::iterator> mp;
  public:
    LRUCache(int cap) {
        this->cap = cap;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        ch.splice(ch.begin(),ch,mp[key]);
        return mp[key]->second;
    }
    void put(int key, int value) {
        if(mp.find(key)==mp.end()) {
            if(ch.size()==cap) {
                auto last = ch.back();
                mp.erase(last.first);
                ch.pop_back();
            }
            ch.push_front(make_pair(key,value));
            mp[key]=ch.begin();
        }
        else {
            mp[key]->second = value;
            ch.splice(ch.begin(),ch,mp[key]);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends