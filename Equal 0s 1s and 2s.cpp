/* Problem Link: https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1

Equal 0, 1 and 2 

Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
 
Example 1:
Input: str = “0102010”
Output: 2
Explanation: Substring str[2, 4] = “102” and substring str[4, 6] = “201” has equal number of 0, 1 and 2 
  
Example 2:
Input: str = “11100022”
Output: 0
Explanation: There is no substring with equal number of 0 , 1 and 2.

Constraints:
1 ≤ N ≤ 105
*/

long long getSubstringWithEqual012(string s) {

    int n = s.size();
    unordered_map<string, int> mp;
    int ans = 0;

    int  c2 = 0, c1 = 0, c0 = 0;      
    string key = to_string(c1-c0) + "#" + to_string(c2-c1);
    mp[key] = 1;

    for(int i = 0; i < n; i++){

       if(s[i] == '2') c2++;
       else if (s[i] == '1') c1++;
       else c0++;

       key = to_string(c1-c0) + "#" + to_string(c2-c1);

       if(mp.count(key) == 1) ans += mp[key];

       mp[key]++;
    }
  
return ans;
}


