/* 
problem Link : https://leetcode.com/problems/reorganize-string/

Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible. 

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""
 
Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

  string reorganizeString(string s) {

      unordered_map<char, int> mp;
      for(char c : s) mp[c]++;

      priority_queue<pair<int, char>> pq;
      for(auto x : mp){
          pq.push(make_pair(x.second, x.first));
      }

      string str = "";
      while(pq.empty() == false){

          if(pq.size() >= 2){
              pair<int, char>p1, p2;
              p1 = pq.top(); pq.pop();
              p2 = pq.top(); pq.pop();

              str += p1.second;
              str += p2.second;
              p1.first--; p2.first--;

              if(p1.first > 0) pq.push(p1);
              if(p2.first > 0) pq.push(p2);
          }

          else if(pq.size() == 1){
              if(pq.top().first > 1) return "";
              else {
                  str += pq.top().second;
                  pq.pop();
              }
          }
      }

  return str;
  }


