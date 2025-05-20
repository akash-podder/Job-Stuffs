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