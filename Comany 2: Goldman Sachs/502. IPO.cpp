class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
	    if(a.first == b.first)
  		    return (a.second > b.second);
 	    return a.first<b.first;
    }
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        // Brute force approach (Time limit exceed)
        // vector<pair<int, int>>vec;
        // int n=profits.size();
        // for(int i=0; i<n; i++){
        //     vec.push_back({profits[i], capital[i]});
        // }
        // sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        // int t=k, x=w;
        // vector<int>vis(n, 0);
        // while(t--){
        //     for(int i=0; i<n; i++){
        //         if(vis[i]==1 || vec[i].second>x)   continue;
        //         x+=vec[i].first;
        //         vis[i]=1;
        //         break;
        //     }
        // }
        // return x;
        
        
        // rember the problem 1834. Single-Threaded CPU siddhesh technique of priority_queue
        vector<pair<int, int>>vec;
        int n=profits.size();
        for(int i=0; i<n; i++){
            vec.push_back({capital[i], profits[i]});
        }
        sort(vec.begin(), vec.end(), sortbysec);
        priority_queue<int>pq;
        if(k>n) k=n;
        int i=0, x=w, t=k;
        for(i=0; i<n; i++){
            while(i<n && vec[i].first<=x){
                pq.push({vec[i].second});
                i++;
            }
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                x+=it;
                t-=1;
                if(t==0)    return x;
                while(i<n && vec[i].first<=x){
                    pq.push({vec[i].second});
                    i++;
                }
            }
        }
        return x;
    }
};
