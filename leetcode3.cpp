class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::iterator start, end;
        string temp;
        int result = 0;
        start = s.begin();
        end = s.begin();
        for (; end < s.end();)
        {
            while (temp.find(*end) < temp.size())
            {
                auto ch = temp.find(*start);
                temp.erase(ch,1);
                start = start + 1;
            }
            result = result > (end - start + 1) ? result : (end - start + 1);
            temp.push_back(*end);
            end++;
        }
        return result;
    }
};
