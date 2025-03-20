class Solution {
public:
    string convert(string s, int numRows) {
        // if numRows==1, we immediately Return the String
        if(numRows==1){
            return s;
        }

        string newStr="";
        int n=s.size();
        int increment=(numRows-1)*2; // if numRows==1, we immediately Return the String... this is the Reason because here we are Subtracting "1" from the "numsRows" value

        for(int row=0;row<numRows;row++){
            for(int j=row;j<n;j=j+increment){
                
                newStr+=s[j];

                // if Row is NOT 0th & LAST Row
                // that means 0<row<n-1
                if(0<row && row<numRows-1){
                    int index = j+increment-(row*2); // this is to take the Zig-Zag Elements... For every "row" we Subtract (2*row) from the "increment" value... just think, we will get it
                    if(index>0 && index<n){
                        newStr+=s[index];
                    }
                }

            }
        }

        return newStr;
    }
};