/* problem Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"

Example 4:
Input: numerator = 4, denominator = 333
Output: "0.(012)"

Example 5:
Input: numerator = 1, denominator = 5
Output: "0.2"
 
Constraints:
-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0
*/
  
        
static bool isPositive(int &num, int &den){
    if((num > 0 && den > 0) || (num < 0 && den < 0)) return true;

return false;
} 

string fractionToDecimal(int num, int den) {

    if(num == 0) return "0"; 

    string ans;            // ans = non-deci + deci

    if (isPositive(num , den) == false)  ans += "-";

    num = abs(num); den = abs(den);

    long long q = num / den;
    long long r = num % den;
    ans += to_string(q);

    if(r == 0) return ans;
    else{
        ans += '.';
        unordered_map<long long, int> mp; 

        while(r != 0){
            if(mp.count(r) == 1){
                ans += ")";
                ans.insert(mp[r], "(");
                return ans;
            } else{
                mp[r]=ans.length();
                r*=10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
    }
return ans; 
}
