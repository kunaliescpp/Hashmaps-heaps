/* Problem Link: https://leetcode.com/problems/top-k-frequent-elements/

Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:

  struct cmp{   // we use struct compare in case of priority queue

      bool operator()(pair<int, int>& a, pair<int, int>& b){
          if(a.second == b.second) return a.first > b.first;      // a.first < b.first
                                                                  // (max heap = reverse of sorting)
          if(a.second < b.second) return true;

      return false;
      }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {

      vector<int>v;
      unordered_map<int,int>mp;

      for(int i: nums) mp[i]++;                                                                      //O(n)

      priority_queue< pair<int,int>, vector<pair<int,int>>, cmp> pq(mp.begin(), mp.end());           //O(n)

      for(int i = 0; i < k; i++){                                                              //O(k * log n)
          v.push_back(pq.top().first);
          pq.pop();
      }

  return v;
  }
};


