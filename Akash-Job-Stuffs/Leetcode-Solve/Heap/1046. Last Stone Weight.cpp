class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            if(pq.size()==1) {
                break;
            }

            int highest=pq.top();
            pq.pop();
            int secondHighest=pq.top();
            pq.pop();

            pq.push(highest-secondHighest);
        }

        return pq.empty()? 0: pq.top();
    }
};