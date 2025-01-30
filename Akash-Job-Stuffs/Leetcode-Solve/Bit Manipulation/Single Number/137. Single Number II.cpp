class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;

        // we iterate each INDEX position for each of the nums. if the Number of i'th Bit is 1 and there Count is Not divisible by 3, that means that belongs to our Desired Number
        for(int i=0;i<32;i++){
            int count_of_one=0;
            for(int j=0;j<nums.size();j++){
                // check if "i'th" Bit is Set to 1
                if((nums[j]&(1<<i))!=0){ //the precedence of the '!=' operator is high, so Remember to Put "()" Brackets properly
                    count_of_one++;
                }
            }
            cout<<count_of_one<<endl;
            // if Count is NOT Divisible by Three that means that Belongs to answer
            if(count_of_one%3!=0){
                ans=ans|(1<<i);
            }
        }

        return ans;
    }
};