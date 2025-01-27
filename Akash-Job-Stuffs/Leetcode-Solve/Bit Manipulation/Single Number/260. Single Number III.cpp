class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int n=0;

        for(int i=0;i<nums.size();i++){
            n=n^nums[i];
        }

        vector<int> v1;
        vector<int> v2;
        
        // n --> Now, Contains XOR of Two Numbers, where the i'th Bit of n is "1", that means the TWO Number has Difference in that Particular i'th INDEX
        for(int bitIndex=0;bitIndex<32;bitIndex++){
            
            // if Bit is SET to 1, we take "i'th" index and Put everyone on that Group Depending upon that index, here we are taking the RIGHT-MOST "1" of "n"
            if(n&(1<<bitIndex)){
                for(int i=0;i<nums.size();i++){
                    if(nums[i]&(1<<bitIndex)){
                        v1.push_back(nums[i]);
                    }
                    else{
                        v2.push_back(nums[i]);
                    }
                }

                break;
            }
        }

        // Now, it is like "Single Number 1" problem
        int x1=0, x2=0;
        for(int i=0;i<v1.size();i++){
            x1=x1^v1[i];
        }
        for(int i=0;i<v2.size();i++){
            x2=x2^v2[i];
        }

        ans.push_back(x1);
        ans.push_back(x2);

        return ans;
    }
};