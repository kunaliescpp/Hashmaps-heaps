/*
Problem Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

Design a data structure that supports insert, delete and getRandom in O(1) time with duplicates not allowed.

*/

class mystructure {
public:
    
    vector<int> v;
    unordered_map<int, int> mp;

    bool insert(int val) {
        if(mp.count(val) == 1) return false;
        
        v.push_back(val);
        mp[val] = v.size()-1;
        
    return true;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0) return false;
        
        int idx = mp[val];
        v[idx] = v[v.size()-1];
        mp[v[v.size()-1]] = idx;
        v.pop_back();
        mp.erase(val);
    
    return true;
    }
        
    int search(int val){
        if(mp.count(val) == 1) return mp[val];
    return -1;
    }
    
    int getRandom() {
      int random = v[rand() % (v.size())];
    return random;
    }
};


