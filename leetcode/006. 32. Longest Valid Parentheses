//Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
//substring.

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxL = 0;
        int right1 = 0, left1 = 0, right2 = 0, left2 = 0;
        int i = 0, j = s.size() -1;
        while(i < s.size()){
            if(s[i] == '(') left1++;
            else right1++;
            if(right1 == left1) maxL = max(maxL, right1);
            else if(right1 > left1) right1 = left1 = 0; 
            if(s[j] == '(') left2++;
            else right2++;
            if(right2 == left2) maxL = max(maxL, right2);
            else if(right2 < left2) right2 = left2 = 0; 
            i++;
            j--;
        }
        return maxL*2;
    }
};
