/* 
problem Link: https://www.lintcode.com/problem/908/

Line Reflection

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Input: [[1,1],[-1,1]]
Output: true

Example 2:
Input: [[1,1],[-1,-1]]
Output: false
*/
    
bool isReflected(vector<vector<int>> &points) {

  int n = points.size();
  int maxi = INT_MIN, mini = INT_MAX;
  unordered_map<int, set<int> > mp;

  for(int i = 0; i < n; i++){
      mini = min(mini, points[i][0]);
      maxi = max(maxi, points[i][0]);
      mp[points[i][0]].insert(points[i][1]); 
  }

  double alpha = double (maxi + mini)/2.0;    // alpha = candidate of line || to y axis
  for(int i = 0; i < n; i++){
      int x2 = 2*alpha-points[i][0];  
    
      if(mp.count(x2) == false || mp[x2].count(points[i][1]) == false) return false;
  }
return true;
}


