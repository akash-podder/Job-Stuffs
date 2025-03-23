class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myWordSet(wordList.begin(), wordList.end()); // O(N)
        map<string, bool> visited;

        queue<string> myQueue;
        myQueue.push(beginWord);

        // we track the Number of Words, Not the Number of Changes... So we start ans=1
        int ans=1;
        
        visited[beginWord] = true;

        while(!myQueue.empty()){

            // we increase ans at EACH LEVEL
            ans++;

            int len = myQueue.size();

            for(int l=0;l<len;l++){

                string currentWord = myQueue.front();
                myQueue.pop();
                
                // Try changing each character of the word, this is done to improve Efficiency
                for(int i=0;i<currentWord.size();i++){
                    
                    for(char ch='a'; ch<='z'; ch++){
                        char originalChar = currentWord[i];
                        currentWord[i] = ch;

                        if(ch == originalChar) continue;
                        
                        // if CurrentWord is Previously NOT Visited
                        if(!visited[currentWord]){ 
                            if(myWordSet.find(currentWord)!=myWordSet.end()){
                                // we Found the Last Word
                                if(currentWord==endWord){
                                    return ans;
                                }

                                visited[currentWord]= true;
                                myQueue.push(currentWord);
                            }
                        }


                            // Assigning back "Original Char" for the Next Loop
                            currentWord[i] = originalChar;
                    }
                }
            }
        }

        // No Matches were Found so, we return 0 as Expected
        return 0;
    }
};