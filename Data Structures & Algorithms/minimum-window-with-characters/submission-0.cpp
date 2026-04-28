class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c : t){
            mp[c]++;
        }

        pair<int,int> res = {-1,-1};
        int minLen = INT_MAX;

        int need = mp.size();
        int have = 0;
        int l = 0;
        unordered_map<char,int> mps;
        for(int r=0;r<s.size();r++){
            mps[s[r]]++;
            if(mp.count(s[r]) && mp[s[r]]==mps[s[r]]){
                have++;
            }

            while(have==need){
                if(r-l+1<minLen){
                    res.first = l;
                    res.second = r;
                    minLen = r-l+1;
                }
                mps[s[l]]--;
                if(mp.count(s[l]) && mp[s[l]] > mps[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(res.first,minLen);
    }
};
