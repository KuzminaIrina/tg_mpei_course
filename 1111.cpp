https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
class Solution {
public:
      vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        bool is = true;
        char old = ')';

        for(auto ch : seq) {
            if ((old == '(' && ch == ')') ||
                (old == ')' && ch == '(')) {
            } else {
                is = !is;
            }
            if (is) res.push_back(1);
            else res.push_back(0);
            old = ch;
        }
        return res;
    }
};
