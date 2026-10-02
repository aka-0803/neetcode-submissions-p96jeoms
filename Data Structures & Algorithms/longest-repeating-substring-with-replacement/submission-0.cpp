class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0;
        int maxf = 0;
        int res =0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxf = max(maxf,mp[s[i]]);
            while((i-l+1)-maxf>k){
                mp[s[l]]--;
                l++;
            }
            res = max(res,(i-l+1));
        }

        return res;
    }
};
