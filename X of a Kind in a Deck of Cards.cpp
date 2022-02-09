/*
Problem Link: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

X of a Kind in a Deck of Cards

In a deck of cards, each card has an integer written on it.
Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
Each group has exactly X cards.
All the cards in each group have the same integer.
 
Example 1:
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
  
Example 2:
Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].
 

Constraints:
1 <= deck.length <= 104
0 <= deck[i] < 104
*/

class Solution {
public:
 
    int gcd(int a, int b){
        if(b == 0) return a;
        int ans = gcd(b, a%b);    // if(a < b) then a and b swapped in the next call
    return ans;
    }
 
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int , int>mp;
        for(auto i: deck) mp[i]++;                  
        
        int g = mp[deck[0]];                           // for deck to be ok frequencies are: 2, 4, 2, 2, 2
        for(auto x: mp){
            g = gcd(g, x.second);
        }
    return g > 1;                                     // gcd of 7 and 2 is 1
    }
};


