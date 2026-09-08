class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int idx = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[i+1]){
                idx = i+1;
                break;
            }
        }
        cout<<idx<<endl;
        int s;
        int e;
        if(nums[n]>=target){
            s = idx;
            e = n;
        }
        else{
            s=0;
            e=idx-1;
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) e = mid-1;
            else s = mid+1;
        }
        return false;
    }
};