/* Problem Link: https://practice.geeksforgeeks.org/problems/check-frequencies4211/1

Check if frequencies can be equal 

Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most 
one character from this string in such a way that frequency of each distinct character becomes same in the string.

Example 1:
Input: s = xyyz
Output: 1 
Explanation: Removing one 'y' will make frequency of each letter 1.

Example 2:
Input: s = xxxxyyzz
Output: 0
Explanation: Frequency can not be made same by removing just 1 character.

Constraints:
1 <= str.length() <= 10^4
*/

class Solution{
public:	

static bool mycmp(pair<int, int>& a, pair<int, int>& b){
    // if(a.second < b.second) return true;
return a.second < b.second;
}


bool sameFreq(string s){

    int n = s.size();
    unordered_map<char, int> mp1;
    for(int i = 0; i < n; i++){
        mp1[s[i]]++;
    }

    unordered_map<int, int> mp2;
    for(auto x : mp1){
        mp2[x.second]++;
    }

    if(mp2.size() == 1) return true;

    else if(mp2.size() == 2){

        vector<pair<int, int>> v;
        for(auto x : mp2){                              // 4 - 1
            v.push_back({x.first, x.second});           // 2 - 2
        }

        sort(v.begin(), v.end(), mycmp);

        if(v[0].first == 1 && v[0].second == 1) return true; // 1 unknown alphabet
        else if(abs(v[1].first - v[0].first) == 1 && v[0].second == 1) return true;
    }

return false;
}
};


