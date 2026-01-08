class MinStack {
public:
    vector<vector<int>>ans;
   
    MinStack() {
       
        
    }
    
    void push(int val) {
        if(ans.empty()){
            ans.push_back({val,val});
        }
        else{
            int currenmin=ans.back()[0];
            ans.push_back({min(currenmin,val),val});
        }
    }
    
    void pop() {
        if(!ans.empty())
        ans.pop_back();
    }
    
    int top() {
       
        return ans.back()[1];
    }
    
    int getMin() {
        return ans.back()[0];
    }
};