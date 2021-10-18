/* Problem Link: https://practice.geeksforgeeks.org/problems/digit-multiplier3000/1

Digit multiplier 

Given a positive integer N, find the smallest number S such that the product of all the digits of S is equal to the number N. 
If there's no such number, Print "-1".

Example 1:
Input: N = 100
Output: 455
Explanation: 4*5*5 = 100. There are no numbers less than 455 with the product of it's digit as 100.

Example 2:
Input: N = 26
Output: -1
Explanation: There are no numbers which can form a product of 26 with its digits.

Constraints:
1 <= N <= 109
*/
    
string getSmallest(long long n) {

    if(n == 1) return "1";
    string str = "";
    int factor = 9;

    while(n > 1 && factor > 1){

        if(n % factor == 0){
            str += (factor+'0');
            n = n/factor;
        } else{
            factor--;
        }
    }

    reverse(str.begin(), str.end());
    if(n == 1) return str;

return "-1";
}
