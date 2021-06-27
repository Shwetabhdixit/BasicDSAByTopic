class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int len = nums.size();
        if(nums[0]>nums[1]) return 0;
        if(nums[len-1]>nums[len-2]) return (len-1);
        
        unsigned long long int index=0;
        unsigned long long int first=1;
        unsigned long long int last=nums.size()-2;
        index=(first+last)/2;
        while(first<=last)
        {
           // cout<<index<<endl;
            index =first + (last-first)/2;
            if(nums[index]>nums[index-1] && nums[index]>nums[index+1])
            {
                return index;
            }
            else if (nums[index+1]>nums[index])
            {
                first=index+1;
            }
            else if(nums[index-1]>nums[index])
            {
                last=index-1;
            }
        }
        return -1;
    }
};
