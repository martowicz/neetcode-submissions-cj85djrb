class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left=0, max=0;
        for (int right=0; right<s.length(); ++right){
            while(charSet.contains(s[right])){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);

            max = std::max(max, right-left+1);
        }
        return max;
    }
};
