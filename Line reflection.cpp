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

    set<pair<int, int>> s;
    int maxi = -1e9, mini = 1e9;
    for(int i = 0; i < n; i++){
        mini = min(mini, points[i][0]);
        maxi = max(maxi, points[i][0]);
        s.insert({points[i][0], points[i][1]});
    }

    for(int i = 0; i < n; i++){
        int x1 = points[i][0], y1 = points[i][1];
        if(s.count({x1, y1}) == 0) continue;

        int x2 = mini+maxi-x1;
        if(s.count({x2, y1}) == 0) return false;
        s.erase({x1, y1}), 
        s.erase({x2, y1});
    }
return true;
}


