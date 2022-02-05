/* Problem Link: https://www.lintcode.com/problem/850/

Employee Free Time

We are given a list schedule of employees, which represents the working time for each employee.
Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
The Intervals is an 1d-array. Each two numbers shows an interval. For example, [1,2,8,10] represents that the employee works in [1,2] and [8,10].
Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Constraints:
1.schedule and schedule[i] are lists with lengths in range [1, 100].
2.0 <= schedule[i].start < schedule[i].end <= 10^8.

Example 1:
Input：schedule = [[1,2,5,6],[1,3],[4,10]]
Output：[(3,4)]
Explanation: There are a total of three employees, and all common free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input：schedule = [[1,3,6,7],[2,4],[2,5,9,12]]
Output：[(5,6),(7,9)]
Explanation：There are a total of three employees, and all common free time intervals would be [-inf, 1], [5, 6], [7, 9],[12,inf]. 
We discard any intervals that contain inf as they aren't finite.


/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// Time complexity: O(total no. of slots * employee number)

vector<vector<int>> employeeFreeTime(vector<vector<int>> &schedule) {

    int n = schedule.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //min heap

    for(int i = 0; i < n; i++){
        for(int j = 0; j < schedule[i].size(); j++){
            pq.push({schedule[i][j], 1});
            j++;
            pq.push({schedule[i][j], 0});
        }
    }

    int cnt = 0;  //workers at curr time
    vector<vector<int>> result;
    while(!pq.empty()){
        pair<int, int> f = pq.top(); pq.pop();

        if(f.second == 1) cnt++;
        else cnt--;

        if(cnt == 0 && !pq.empty()){
          pair<int, int> s = pq.top(); //pq.pop();
          if(f.second == 0 && s.second == 1){
              if(cnt == 0) result.push_back({f.first, s.first});
          }  
        }
    }

return result;
}

int32_t main(){
    
    vector<vector<int>> v  = {{1,3,6,7},{2,4},{2,5,9,12}};

    vector<vector<int>> ans = employeeFreeTime(v); 
    for(vector<int>& vect1d: ans){
        cout << "[" << vect1d[0] << "," << vect1d[1] << "]" << " ";
    }

return 0;
}
