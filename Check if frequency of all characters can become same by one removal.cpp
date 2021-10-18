/* Problem Link: https://practice.geeksforgeeks.org/problems/check-frequencies4211/1

Check if frequencies can be equal 

Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most 
one character from this string in such a way that frequency of each distinct character becomes same in the string.

Example 1:
Input: s = xyyz
Output: 1 
Explanation: Removing one 'y' will make frequency of each letter 1.

Example 2:
Input: s = xxxxyyzz
Output: 0
Explanation: Frequency can not be made same by removing just 1 character.

Constraints:
1 <= str.length() <= 10^4
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
