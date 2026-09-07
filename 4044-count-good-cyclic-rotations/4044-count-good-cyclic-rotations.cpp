class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long suml = 0;
        long long sumr = 0;
        for(int i=0;i<nums.size()/2;i++){
            suml+=nums[i];
        }
        for(int i=nums.size()/2;i<nums.size();i++){
            sumr+=nums[i];
        }
        int i = 0;
        int j = nums.size()/2;
        int n = nums.size();
        int cnt = 0;
        while(n--){
            suml-=nums[i];
            suml+=nums[j];
            sumr-=nums[j];
            sumr+=nums[i];
            if(suml>sumr) cnt++;
            i = (i+1)%nums.size();
            j = (j+1)%nums.size();
        }
        return cnt;
    }
};