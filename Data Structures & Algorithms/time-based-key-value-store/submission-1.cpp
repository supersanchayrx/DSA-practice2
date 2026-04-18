class TimeMap {

    unordered_map<string,vector<pair<string,int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        int left = 0;
        int right = mp[key].size()-1;

        auto& arr = mp[key];

        while(left<=right)
        {
            int mid = (left+right)/2;

            if(arr[mid].second==timestamp)
                return arr[mid].first;
            
            else if(arr[mid].second>timestamp)
            {
                right = mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        if(right>=0)
            return arr[right].first;

        return "";
    }
};
