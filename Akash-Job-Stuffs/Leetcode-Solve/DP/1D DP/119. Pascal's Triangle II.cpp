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

    vector<int> solve(int &numRows){
        vector<int> ans;

        // for numRows=1, we at first Push "1" in the Vector
        ans.push_back(1);

        for(int i=0; i<numRows; i++){
            ans = getNPascalVector(i, ans);
        }

        return ans;
    }

    vector<int> getRow(int rowIndex) {
        return solve(rowIndex);
    }
};