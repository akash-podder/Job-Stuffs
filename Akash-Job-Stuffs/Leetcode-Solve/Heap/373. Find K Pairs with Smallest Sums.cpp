class Solution {
public:

    typedef pair<int, pair<int, int>> customP; // {sum, {i, j}} eivabe rakhar jonno
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        priority_queue<customP, vector<customP>, greater<customP>> pq; // Min Heap with the FIRST Element (which represents "SUM" in this case) as the lowest Value

        set<pair<int, int>> visited;

        int len1=nums1.size();
        int len2=nums2.size();

        int sum = nums1[0]+nums2[0];
        
        // we push the (0, 0) pair
        pq.push({sum, {0, 0}});
        visited.insert(make_pair(0, 0));

        // we EXIT if we Found "k" pairs OR, we have exchausted LOOPING all the Pairs... pq.empty will Only happen when there are No More Combination of Pair can be Made
        while(k && !pq.empty()){
            
            // As, the Minheap Ensures ALWAYS the LOWEST value will be in the TOP
            int i=pq.top().second.first;
            int j=pq.top().second.second;

            // (i, j) has been added to answer
            ans.push_back({nums1[i], nums2[j]});

            pq.pop();


            // Push (i+1, j) if Possible & previously NOT Visited
            if(i+1<len1 && visited.find(make_pair(i+1, j))==visited.end()){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert(make_pair(i+1, j));
            }

            // Push (i, j+1) if Possible & previously NOT Visited
            if(j+1<len2 && visited.find(make_pair(i, j+1))==visited.end()){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert(make_pair(i, j+1));
            }
            
            k--;
        }

        return ans;
    }
};