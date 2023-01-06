class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        if(n<=2)    return 0;
        for(int i=0; i<n; i++){
            map<int, int>mp;
            for(int j=0; j<n ; j++){
                int d=pow((points[j][0]-points[i][0]),2)+pow((points[j][1]-points[i][1]),2);
                mp[d]++;
            }
            for(auto it: mp){
                if(it.second >= 2)
                    ans+=((it.second-1)*(it.second));
            }
            cout << "\n\n";
        }
        return ans;
    }
};
