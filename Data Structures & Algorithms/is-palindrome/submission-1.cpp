class Solution {
public:
    bool isPalindrome(string s) {
      string new_s = "";
      int n = s.size();
      for(int i=0;i<n;i++){
        char c = s[i];
        if(isalnum(c)){
            new_s += tolower(c);
        }
      }


       string reverse_s(new_s.rbegin(),new_s.rend());

       for(int i=0;i<new_s.size();i++){
        if(reverse_s[i]!=new_s[i]) return false;
       }

       return true;
       
    }
};
