class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> Map;
        auto  begin = nums.begin();
        Map.insert(pair<int, int>(*begin, 0));
        for (auto ptr = begin + 1,end = nums.end(); ptr < end; ptr++)
        {
            if (Map.count(target - *ptr))
            {  
                result.push_back(ptr - begin), result.push_back(Map[target-*ptr]);
                return result;
            }
            Map.insert(pair<int, int>(*ptr, ptr - begin));
        }
        return result;

    }
};
