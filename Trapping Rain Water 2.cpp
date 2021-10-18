/* Problem Link: https://leetcode.com/problems/trapping-rain-water-ii/

Trapping Rain Water II

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return 
the volume of water it can trap after raining.

Example 1:
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks. We have two small pounds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2:
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104
*/


class Solution {
public:
    
    class position{
        public : 
        int row;
        int col;
        int height;

        position(int r, int c, int h){
            row = r;
            col = c;
            height = h;
        }     
    }; 
    
    struct mycmp{
        bool operator()(position &a, position &b){
        
            return a.height < b.height;
        }
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {

        priority_queue<position, vector<position>, mycmp> pq;
        
        int m = heightMap.size();
        if(m == 0) return 0;
        int n = heightMap[0].size();
        
        vector<vector<bool>>visited(m, vector<bool> (n, false));
        
        // Pushes boundary in min heap
        for (int j = 0; j < n; j++) {
            pq.push(position(0, j, heightMap[0][j]));
            visited[0][j] = true;
        }
        
        for (int j = 0; j < n; j++) {
            pq.push(position(n-1, j, heightMap[n-1][j]));
            visited[n-1][j] = true;
        }
        
        for(int i = 1; i <= m-2; i++) {
            pq.push(position(i, 0, heightMap[i][0]));
            visited[i][0]=true;
        }
        
        for(int i = 1; i <= m-2; i++) {
            pq.push(position(i, m-1, heightMap[i][m-1]));
            visited[i][m-1]=true;
        }
        
        int vol = 0;
        int minBdht = 0;              // min_boundary_height
        while(!pq.empty()){
            
            int r = pq.top().row;
            int c = pq.top().col;
            int currHt = pq.top().height;
            pq.pop();
            
            minBdht = max(currHt, minBdht);
            
            // checking its adjacent
            int dx[4] = { 1, -1, 0, 0};
            int dy[4] = { 0, 0, -1, 1};
            
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && visited[nr][nc] == false){
                    
                    pq.push(position(nr, nc, heightMap[nr][nc]));
                    visited[nr][nc] = true;
                    if(heightMap[nr][nc] < minBdht){   // inner element of boundary is small
                        vol += minBdht - heightMap[nr][nc];
                    }  
                }
            } // checking done
        } 
    return vol;
    }
};
