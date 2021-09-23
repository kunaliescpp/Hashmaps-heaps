/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Kth Smallest Element in a Sorted Matrix

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:
n == matrix.length
n == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

class Solution {
public:

    class position{
        public : 
        int row;
        int col;
        int val;

        position(int r, int c, int v){
            row = r;
            col = c;
            val = v;
        }     
    };
    
    static bool mycmp(position &a, position &b){ 
        return a.val < b.val;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        priority_queue<position, vector<position>, mycmp> pq;
        
        for(int i = 0; i < m; i++){
            pq.push(position(i, 0, matrix[i][j]));
        }
       
        int cnt = 0;
        while(!pq.empty()){
            int r = pq.top().row;
            int c = pq.top().col;
            int v = pq.top().val;
            cnt++;
            
            if(cnt == k) return v;
            if(c+1 <= n-1) pq.push(r, c+1, matrix[r][c+1]);   
        }
    return 0;
    }
};
