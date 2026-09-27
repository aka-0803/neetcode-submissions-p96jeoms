class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string res;
        for(auto str : strs){
            res.append(to_string(str.size()));
            res.append("#");
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s=="") return {};
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            string temp = s.substr(i,j-i);
            res.push_back(temp);
            i=j;
        }
        return res;
    }
};
