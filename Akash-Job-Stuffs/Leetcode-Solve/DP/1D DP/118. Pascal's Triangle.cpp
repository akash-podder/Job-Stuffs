class Solution {
public:
    vector<int> getNPascalVector(int n, vector<int> v){
        vector<int> temp;

        temp.push_back(1);

        for(int i=1;i<v.size();i++){
            // the Current Element is the Sum of Previous Vector's Current Element+Previous Element
            int x=v[i]+v[i-1];
            temp.push_back(x);
        }

        temp.push_back(1);

        return temp;
    }

    vector<vector<int>> solve(int &numRows){
        vector<vector<int>> ans;
        vector<int> v;

        // for numRows=1, we at first Push "1" in the Vector
        v.push_back(1);

        for(int i=0; i<numRows; i++){
            ans.push_back(v);
            v = getNPascalVector(i, v);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        return solve(numRows);
    }
};