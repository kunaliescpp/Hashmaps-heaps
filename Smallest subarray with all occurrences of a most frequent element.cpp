/* Problem Link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-all-occurrences-of-a-most-frequent-element2258/1

Smallest subarray with all occurrences of a most frequent element 

Given an array A. Let X be an element in the array which has the maximum frequency. The task is to find the smallest
sub segment of the array which also has X as the maximum frequency element.

Note: if two or more elements have the same frequency (i.e., maximum frequency) and the same sub segment size then 
print the sub segment which occurs first in the array.

Example 1:
Input : A[] = {1, 2, 2, 3, 1}
Output : 2 2
Explanation: Note that there are two elements that appear two times, 1 and 2.The smallest window for 1 is whole array and
smallest window for 2 is {2, 2}. Since window for 2 is smaller, this is our output.

Example 2:
Input : A[] = {1, 4, 3, 3, 5, 5} 
Output : 3 3 

Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
*/

class element{
    public:
    int freq;
    int si;
    int ei;

    element(int f, int s, int e){
        freq = f;
        si = s;
        ei = e;
    }
};

vector<int> smallestSubsegment(int a[], int n){

  unordered_map<int, element> mp;;
  for (int i = 0 ; i < n ; i++){
      if(mp.count(a[i]) == 1){
          element e = mp[a[i]];
          e.freq++;
          e.ei = i;;
          mp[a[i]] = e;
      } else{
          mp[a[i]] = {1, i, i};
      }
  }

  int maxFreq = 0;
  element maxi = {100000, 0, 10000};
  for (auto x : mp){
      if(maxFreq < x.second.freq){
          maxFreq = x.second.freq;
          maxi = x.second;
      }

      else if(maxFreq == x.second.freq){
          int len1 = x.second.ei - x.second.si + 1;
          int len2 = maxi.ei - maxi.si + 1;
          if(len1 < len2) maxi = x.second;
      }
  }

  vector<int> res;
  for(int i = maxi.si; i <= maxi.ei; i++){
      res.push_back(a[i]);
  }

return res;
}
