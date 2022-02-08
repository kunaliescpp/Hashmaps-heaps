/* 
Problem Link: https://practice.geeksforgeeks.org/problems/pairs-of-non-coinciding-points4141/1

Pairs of Non Coinciding Points 

In a given cartesian plane, there are N points. We need to find the Number of Pairs of points(A, B) such that Point A and Point B
do not coincide.

Manhattan Distance and the Euclidean Distance between the points should be equal.
Note: Pair of 2 points(A,B) is considered same as Pair of 2 points(B ,A).
Manhattan Distance = |x2-x1|+|y2-y1|
Euclidean Distance   = ((x2-x1)^2 + (y2-y1)^2)^0.5, where points are (x1,y1) and (x2,y2).

Example 1:
Input: N = 2
X = {1, 7}
Y = {1, 5}
Output: 0
Explanation: None of the pairs of points have equal Manhatten and Euclidean distance.

Example 2:
Input: N = 3
X = {1, 2, 1}
Y = {2, 3, 3}
Output: 2
Explanation: The pairs {(1,2), (1,3)}, and {(1,3), (2,3)} have equal Manhatten and Euclidean distance.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
 -10^9 <= X[i], Y[i] <= 10^9
*/

int numOfPairs(int X[], int Y[], int N) {
    map<int, int> mp1, mp2;
    map<pair<int, int>, int> mp3;   // test case: (11,11), (11,33), (33, 22), (33, 22)
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(mp1.count(X[i]) == 1) cnt+= mp1[X[i]];
        if(mp2.count(Y[i]) == 1) cnt+= mp2[Y[i]];
        if(mp3.count({X[i], Y[i]}) == 1) cnt-= (2*mp3[{X[i], Y[i]}]);

        mp1[X[i]]++;
        mp2[Y[i]]++;
        mp3[{X[i], Y[i]}]++;
    }

return cnt;
}


