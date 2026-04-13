class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size(), 1);
        int left = 1;
        for(int i = 0; i<n; ++i){
            res[i] = left;
            left*=nums[i];
        }
        int right = 1;
        for (int j=n-1;j>=0;--j){
            res[j]*=right;
            right*=nums[j];
        }
        return res;

    }
};
