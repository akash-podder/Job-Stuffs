class Solution {
public:
    struct PointsWithDistance{
        int x;
        int y;
        int distance;

        PointsWithDistance(int _x, int _y, int _d) {
            x = _x;
            y = _y;
            distance = _d;
        }

        // Define > operator so std::greater can work
        bool operator>(const PointsWithDistance& other) const {
            return distance > other.distance;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // √(x1 - x2)2 + (y1 - y2)2) --> As all the Numbers are "SQRT" so, we just ignore it for Better Comparison

        priority_queue<PointsWithDistance, vector<PointsWithDistance>, greater<PointsWithDistance>> minHeap;
        for(int i=0; i<points.size(); i++){

            int temp_x = points[i][0]-0;
            int temp_y = points[i][1]-0;

            int distance = (temp_x * temp_x) + (temp_y * temp_y);

            PointsWithDistance tempPoint(points[i][0], points[i][1], distance);

            minHeap.push(tempPoint);
        }

        vector<vector<int>> ans;

        while(k--){
            PointsWithDistance temPoint = minHeap.top();
            minHeap.pop();

            vector<int> temp;
            temp.push_back(temPoint.x);
            temp.push_back(temPoint.y);

            ans.push_back(temp);
        }

        return ans;
    }
};