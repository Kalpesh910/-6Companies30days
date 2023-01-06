class Solution{ 
public:
    float dis(vector<int>& p1, vector<int>& p2){
        int x1=p1[0], y1=p1[1], x2=p2[0], y2=p2[1];
        int x=(x2-x1)*(x2-x1);
        int y=(y2-y1)*(y2-y1);
        return x+y;
    }
    bool perpendicular(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        int x1, x2, y1, y2;
        x1 = p1[0]-p2[0];
        y1 = p1[1]-p2[1];
        x2 = p3[0]-p4[0];
        y2 = p3[1]-p4[1];
        if(x1==0 && y2!=0)  return false;
        if(x2==0 && y1!=0)  return false;
        if(y1==0 && x2!=0)  return false;
        if(y2==0 && x1!=0)  return false;
        if(y1*y2 != -x1*x2) return false;
        return true;
    }
    bool f2(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        bool a=perpendicular(p1, p4, p1, p3);
        bool b=perpendicular(p1, p4, p2, p4);
        bool c=perpendicular(p2, p4, p2, p3);
        bool d=perpendicular(p1, p3, p2, p3);
        if(!a||!b||!c||!d)  return false;
        float d1 = dis(p1, p3);
        float d2 = dis(p1, p4);
        if(d1 != d2)    return false;
        float d3 = dis(p2, p3);
        if(d3!=d2)  return false;
        float d4 = dis(p2, p3);
        if(d4!=d1)  return false;
        return true;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        1st Solution
        
        if(p1==p2 || p2==p3 || p1==p3)  return false;
        if(f2(p1, p2, p3, p4)==true)    return true;
        if(f2(p4, p2, p3, p1)==true)    return true;
        if(f2(p4, p1, p2, p3)==true)    return true;
        return false;
        
        
        
//         //2nd Solution small code
        
//         if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4)    return false;
//         map<int, int>mp;
//         int a=pow((p1[0]-p2[0]),2) + pow((p1[1]-p2[1]),2);
//         int b=pow((p1[0]-p3[0]),2) + pow((p1[1]-p3[1]),2);
//         int c=pow((p1[0]-p4[0]),2) + pow((p1[1]-p4[1]),2);
//         int d=pow((p2[0]-p4[0]),2) + pow((p2[1]-p4[1]),2);
//         int e=pow((p2[0]-p3[0]),2) + pow((p2[1]-p3[1]),2);
//         int f=pow((p4[0]-p3[0]),2) + pow((p4[1]-p3[1]),2);
//         mp[a]++;
//         mp[b]++;
//         mp[c]++;
//         mp[d]++;
//         mp[e]++;
//         mp[f]++;
//         if(mp.size()>2) return false;
//         return true;
    }
};
