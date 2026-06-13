class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
            
             if(mpp.find(key)==mpp.end()){
                 return "";
             }

             vector<pair<int,string>>&vec = mpp[key];

             int low=0;
             int high=vec.size()-1;

             string ans="";

             while(low<=high){
                int mid=(low+high)/2;

                if(vec[mid].first<=timestamp){
                     ans=vec[mid].second;
                     low=mid+1;
                }
                else{
                    high=mid-1;
                }
             }

             return ans;
    }
};

