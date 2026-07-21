class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            vector<int> freq(26,0);
            for(auto c : str){
                freq[c-'a']++;
            }
            string key = to_string(freq[0]);
            for(int i=1;i<26;i++){
                key += ',' + to_string(freq[i]);
            }
            hash[key].push_back(str);
        }

        for(auto val : hash){
            res.push_back(val.second);
        }

        return res;
    }
};
