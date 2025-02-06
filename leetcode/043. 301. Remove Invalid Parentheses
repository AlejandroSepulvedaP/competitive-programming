class Solution {
public:
    pair<set<string>, string> helper(string s, char cl, char cr) {
        set<string> ans;        
        ans.insert("");        
        int i = 0;
        int start = 0;
        int lcnt = 0, rcnt = 0;
        int n = s.size();
        while (i < n) {
            if (s[i] == cr) {                                
                if (++rcnt > lcnt) {
                    // Everytime the `cr` cnt is higher than `cl` count,
                    // we remove 1 cr from all possible s[0..i]
                    set<string> nans;
                    for (auto str : ans) {
                        set<string> st;
                        string sR = str + s.substr(start, i + 1 - start);
                        // Remove `cnt` number of char `cr`
                        for (int m = 0;m < sR.size(); ++m) {
                            if (sR[m] == cr) {
                                st.insert(sR.substr(0, m)+sR.substr(m + 1));
                            }
                        }
                        for (auto str2 : st) {
                            nans.insert(str2);
                        }
                    }
                    swap(nans, ans);
                    // we already have a set of `ans`, each of which 
                    // is valid with same counts for `cl` and `cr`.
                    start = i + 1;
                    rcnt--;                    
                }
            } else if (s[i] == cl) {                                
                lcnt++;
            }
            ++i;
        }
        // lcnt >= rcnt;   
        // Return the set of strings that we removed some `cr`,
        // and a left-over string that we didn't delete anything.      
        return {ans, s.substr(start)};
    }

    vector<string> removeInvalidParentheses(string s) {        
        auto p1 = helper(s, '(', ')');
        set<string>& ans1 = p1.first;        
        auto s1 = p1.second;

        // s1 may contain lcnt > rct, so we need to do another pass to remove some cl.
        // notice here we set cl=')' and cr='(' because we want to remove extra count
        // from lcnt to be matched with rcnt.
        reverse(s1.begin(), s1.end());
        auto p2 = helper(s1, ')', '(');        
        set<string>& ans2 = p2.first;
        auto s2 = p2.second;        
        reverse(s2.begin(), s2.end());
        // s2 should either contain no parenthesis or the same left and right parenthesis.                

        // Then we concat each string in ans1 + reversed(s2) + reversed(each string in ans2); 
        vector<string> ans;
        for (auto x : ans1) {
            for (auto y : ans2) {
                //cout << "y: " << y << endl;
                reverse(y.begin(), y.end());
                ans.push_back(x + s2 + y);
            }
        }
        return ans;
    }
};
