class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // n2 - generate every substring
        if(s1.size()>s2.size()) return false;
        int l=0;
        int r=s1.size()-l-1;
        sort(s1.begin(),s1.end());
        while(r<s2.size()){
            string v = s2.substr(l,(r-l+1));
            sort(v.begin(),v.end());
            if(v==s1) return true;
            r++;
            l++;
        }
        return false;
    }
};
