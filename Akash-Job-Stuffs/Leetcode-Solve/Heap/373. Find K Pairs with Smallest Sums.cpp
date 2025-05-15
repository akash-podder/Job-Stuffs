// ---------------------------SOLVE-1-----------------------------------------
class MyPair{
public:
    int i;
    int j;
    int sum;

    MyPair(int a, int b, int s){
        i = a;
        j = b;
        sum = s;
    }
};

class MyComparator{
public:
    bool operator()(const MyPair& a, const MyPair& b) {
        return a.sum > b.sum; // Min Heap
    };
};

class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<MyPair, vector<MyPair>, MyComparator> pq;

        vector<vector<int>> ans;
        
        map<pair<int, int>, bool> visited; // there can be Duplicate Pairs, as such we have to check we have already visited it or Not
        
        pq.push(MyPair(0, 0, nums1[0]+nums2[0]));
        
        while(!pq.empty() && k>0){
            // Decrementing the count
            k--;

            MyPair top = pq.top();
            
            pq.pop();
            int i = top.i;
            int j = top.j;
            visited[{i,j}] = true; // As, the Minheap Ensures ALWAYS the LOWEST value will be in the TOP, we add {i, j} Pair to answer


            ans.push_back({nums1[i], nums2[j]});

            // Push (i+1, j) if Possible & previously NOT Visited
            if(i+1 < nums1.size()){
                if(visited[{i+1, j}]==false){
                    pq.push(MyPair(i+1, j, nums1[i+1]+nums2[j]));
                    visited[{i+1, j}]=true; // after Pushing it to "pq" we need to Mark it as Visited IMMEDIATELY, otherwise we can push the same element in the NEXT Loop
                }
            }

            // Push (i, j+1) if Possible & previously NOT Visited
            if(j+1 < nums2.size()){
                if(visited[{i, j+1}]==false){
                    pq.push(MyPair(i, j+1, nums1[i]+nums2[j+1]));
                    visited[{i, j+1}]=true; // after Pushing it to "pq" we need to Mark it as Visited IMMEDIATELY, otherwise we can push the same element in the NEXT Loop
                }
            }
        }

        return ans;
    }
};


// ---------------------------SOLVE-2-----------------------------------------
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