class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }

        for(int i=0;i<t.size();i++){
            if(hash[t[i]]>0){
                hash[t[i]]--;
            }else{
                return false;
            }
        }

        for(auto val : hash){
            if(val.second>0){
                return false;
            }
        }

        return true;
    }
};
