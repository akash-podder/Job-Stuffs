// -------------------- Java Solve --------------------------
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);

        int len = citations.length;

        int ans = 0;

        int low = 0;
        int high = len-1;

        // we are doing Binary Search to Find Furthest element from the "End" (OR, "high" in Binary Search), such that the Value "(citations[mid])" in that INDEX is Greater than Equal to the Distance from the "End"
        while(low<=high){
            int mid = low + ((high-low)/2);
            
            // Move to Left
            if((len-mid)<=citations[mid]){
                high = mid-1;
                ans = len-mid;
            }

            // Move to Right
            else{
                low = mid+1;
            }
        }

        return ans;
    }
}

// -------------------- C++ Solve --------------------------
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 0;
        
        //At First we Sort the Array
        sort(citations.begin(),citations.end());
        
        // then we do Binary Search to Find the "index" of that element which's Right Element COUNT >= index's Element
        int low = 0, high = citations.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            //"index" of that element which's (Right Element COUNT >= index's Element), then we Store it to "h_index" variable & move the "high" pointer to LEFT to find the Optimal Answer
            if(citations[mid]>=(citations.size()-mid)){
                h_index = citations.size()-mid;
                high = mid-1;
            }
            // otherwise, we move the "low" pointer to RIGHT
            else{
                low = mid+1;
            }
        }
        
        return h_index;
    }
};