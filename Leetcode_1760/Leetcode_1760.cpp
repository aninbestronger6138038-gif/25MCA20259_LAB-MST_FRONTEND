class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int highest =nums[0];
        //fetching the bag with highest no of balls
        for(int i=0;i<n;i++){
            if(highest<nums[i]){
                highest=nums[i];
            }
        }

        int low=1;
        int high= highest;
        int penalty=0;

        while(low<=high){
            int mid= low+(high-low)/2;
            int operations=0;

            for(int i=0;i<n;i++){
                operations+= (nums[i]-1) / mid;
                if(operations > maxOperations )
                    break;
            }        
            if (operations <= maxOperations){
                penalty=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

            }
        
        return penalty;
    } 
};
