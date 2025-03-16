class Solution {
public:
    bool isNextGene(string currentGene, string nextGene){
        int coun=0;
        for(int i=0;i<currentGene.size();i++){
            if(currentGene[i]!=nextGene[i]){
                coun++;
            }

            if(coun>1){
                return false;
            }
        }

        return true;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string, vector<string>> Map;
        map<string, int> visited;
        queue<string> myQueue;
        myQueue.push(startGene);

        int coun=0;

        while(!myQueue.empty()){
            coun++; // for Each Level Traversing we add "1" to our Answer

            int len = myQueue.size(); // this is to Track UPTO which Element in the Queue belongs to SAME Level
            
            for(int l=0;l<len;l++){
                string currentGene = myQueue.front();
                myQueue.pop();
                
                for(int i=0;i<bank.size();i++){
                    if(isNextGene(currentGene, bank[i]) && visited[bank[i]]==false){

                        // this Means, our nextGene is the "endGene", so just Return ans
                        if(bank[i]==endGene){
                            return coun;
                        }

                        visited[bank[i]]=true;
                        myQueue.push(bank[i]);
                    }
                }
            }
        }

        // this Means, our Could Not reach to "endGene", so just Return "-1"
        return -1;
    }
};