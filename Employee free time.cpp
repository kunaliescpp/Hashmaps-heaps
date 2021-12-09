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

vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {

    int n = schedule.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //min heap

    for(int i = 0; i < n; i++){
        for(int j = 0; j < schedule[i].size(); j+=2){
            pq.push(make_pair(schedule[i][j], 0));
            pq.push(make_pair(schedule[i][j+1], 1));
        }
    }

    int cnt = 0;  //workers at curr time
    vector<Interval> result;
    while(!pq.empty()){
        pair<int, int> left = pq.top(); pq.pop();

        if(left.second == 0) cnt++;
        else cnt--;

        pair<int, int> right = pq.top(); //pq.pop();
        if(left.second == 1 && right.second == 0){
            if(cnt == 0) result.push_back(Interval(left.first, right.first));
        }
    }

return result;
}


