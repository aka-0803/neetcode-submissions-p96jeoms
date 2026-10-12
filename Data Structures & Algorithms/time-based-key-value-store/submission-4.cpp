class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // if(mp.find(key)!=mp.end()){
        //     auto arr = mp[key];
        //     arr.push_back({timestamp,value});
        //     mp[key] = arr;
        // }else{
        //     vector<pair<int,string>> temp;
        //     temp.push_back({timestamp,value});
        //     mp[key] = temp;
        // }
        mp[key].push_back({timestamp,value});
    }
    
    // string searchHelper(int target,vector<pair<int,string>>& arr){
    //     int l = 0;
    //     int r = arr.size()-1;
    //     int ind = -1;
    //     while(l<=r){
    //         int mid = l+(r-l)/2;
    //         int midTimeStamp = arr[mid].first;
    //         if(midTimeStamp<=target){
    //             ind = mid;
    //             l=mid+1;
    //         }else{
    //             r=mid-1;
    //         }
    //     }
    //     if(ind==-1){
    //         return "";
    //     }

    //     return arr[ind].second;
    // }

    string get(string key, int timestamp) {
        // if(mp.find(key)==mp.end()){
        //     return "";
        // }
        auto& arr = mp[key];
        // string res = searchHelper(timestamp,arr);
        int l = 0;
        int r = arr.size()-1;
        int ind = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int midTimeStamp = arr[mid].first;
            if(midTimeStamp<=timestamp){
                ind = mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(ind==-1){
            return "";
        }

        return arr[ind].second;
        //return res;
    }
};
