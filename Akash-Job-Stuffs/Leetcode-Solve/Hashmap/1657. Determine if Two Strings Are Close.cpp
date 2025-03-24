class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> m1;
        map<char, int> m2;

        if(word1.size()!=word2.size()){
            return false;
        }

        // if BOTH size is EQUAL
        int len = word1.size();

        for(int i=0;i<len;i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        // if Both String doesn't have EQUAL Number of DISTINCT Characters then it Can't be Transformed
        if(m1.size()!=m2.size()){
            return false;
        }


        // Check if the CHARACTERs "frequencies" are EQUAL
        auto it1 = m1.begin();
        auto it2 = m2.begin();

        vector<int> v1;
        vector<int> v2;

        for(int i=0;i<m1.size();i++){
            v1.push_back(it1->second);
            v2.push_back(it2->second);

            // Operation-2 :every occurrence of one EXISTING character into another EXISTING character
            // **** That's why we check if the Same Characters Exist in the Both the STRINGs ***
            if(it1->first!=it2->first){
                return false;
            }
            it1++;
            it2++;
        }

        // all the Frequencies are Stored in v1 & v2 vectors
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for(int i=0;i<v1.size();i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }
};