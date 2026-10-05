class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="*" && tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/"){
                int num = stoi(tokens[i]);
                q.push(num);
            }else{
                int num1 = q.top();
                q.pop();
                int num2 = q.top();
                q.pop();
                int res = 0;
                if(tokens[i]=="+"){
                    res = num1+num2;
                }else if(tokens[i]=="-"){
                    res = num2-num1;
                }else if(tokens[i]=="*"){
                    res = num2*num1;
                }else if(tokens[i]=="/"){
                    res = num2/num1;
                }
                q.push(res);
            }
        }
        return q.top();
    }
};
