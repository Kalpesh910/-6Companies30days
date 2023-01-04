class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        temp=nums;
        sort(temp.begin(), temp.end());
        int found=0, start=-1, end=-1;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=temp[i]){
                start=i;
                break;
            }
            i++;
        }
        int j=nums.size()-1;
        while(j>=0){
            if(nums[j]!=temp[j]){
                end=j;
                break;
            }
            j--;
        }
        if(end==-1 || start==-1)    return 0;
        return end-start+1;
    }
};
