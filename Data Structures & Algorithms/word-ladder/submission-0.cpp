class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        unordered_map<string,int> visited;
        unordered_map<string,int> list;
        for(auto word : wordList){
            list[word]++;
        }
        visited[beginWord] = 1;
        int cnt = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr = q.front();
                q.pop();
                for(int ind=0;ind<curr.size();ind++){
                    char c = curr[ind];
                    for(char x='a';x<='z';x++){
                        curr[ind] = x;
                        if(list.find(curr)!=list.end()){
                            if(visited.find(curr)==visited.end()){
                                if(curr==endWord){
                                    return cnt+1;
                                }
                                q.push(curr);
                                visited[curr]++;
                            }
                        }
                    }
                    curr[ind] = c;
                }
            }
            cnt++;
        }

        return 0;
    }
};
