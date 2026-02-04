class Solution{
public:
  int findmax(vector<int>&nums){
    int max=nums[0];
    for(int i=1;i<nums.size();i++){
    if(max>nums[i){
    max=nums[i];
    }
  }
return max;
};
