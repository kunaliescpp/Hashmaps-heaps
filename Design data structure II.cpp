/*
Problem Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

Design a data structure that supports insert, delete, getRandom in O(1) with duplicates allowed.
*/                                                                                
                                                                                                                                                                
class mystructure {
   public:
    
    vector<int> v;
    map<int, set<int>> mp;                  // 5 ->  idx | true
    
    bool insert(int val) {
        bool ans = mp.count(val);
        v.push_back(val);
        mp[val].insert(v.size()-1);
    return (1-ans);
    }
    
    bool remove(int val){
        if(mp.count(val) == 0) return false;
    
        auto it = mp[val].begin();
        int idx = *it;
        // int idx = *(mp[val].begin());   
        mp[val].erase(mp[val].begin());
        
        int temp = v.back();
        v[idx] = temp;
        mp[temp].insert(idx);
        mp[temp].erase(v.size()-1);                       
        v.pop_back();
        
        if(mp[val].size() == 0) mp.erase(val);
        
    return true;
    }
    
    int getRandom() {     
        int random = v[rand() % (v.size())];
    return random;
    }
};
   

