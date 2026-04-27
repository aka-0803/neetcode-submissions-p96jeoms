class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int h = 0;

        if(s==""){
            return 0;
        }

        int n = s.size();
        unordered_map<char,int> mp;
        int maxLen = 0;
        while(h<n){
            mp[s[h]]++;
            while(mp[s[h]]>1){
                mp[s[l]] -=1;
                l++;
            }
            int val = h-l+1;
            maxLen = max(maxLen,val);
            h++;
        }

        return maxLen;
    }
};
