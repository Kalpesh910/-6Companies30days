class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i, int sum, vector<int>temp, int n, int k){
        if(i>9) return;
        int size = temp.size();
        if(sum+i>n || size+1>k) return;
        if(sum+i==n && i!=0 && temp.size()==k-1){
            temp.push_back(i);
            ans.push_back(temp);
            return;
        }
        fun(i+1, sum, temp, n, k);
        if(i!=0){
        temp.push_back(i);
        fun(i+1, sum+i, temp, n, k);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        fun(0, 0, temp, n, k);
        return ans;
    }
};
