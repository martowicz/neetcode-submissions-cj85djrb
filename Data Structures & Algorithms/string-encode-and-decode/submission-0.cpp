class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result = "";
        for(const std::string& s : strs){
            result += std::to_string(s.length()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;

        int i=0;

        while (i < s.length()){
            int j = s.find("#",i);

            int length = std::stoi(s.substr(i, j - i));
            i = j + 1;

            result.push_back(s.substr(i, length));

            i += length;

        }
        return result;

    }
};
