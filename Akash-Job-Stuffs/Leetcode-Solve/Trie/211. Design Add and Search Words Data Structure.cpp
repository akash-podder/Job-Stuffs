class Node{
public:
    map<char, Node*> Map;
    bool isLastChar;

    Node(){
        isLastChar = false;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();    
    }

    bool dfs(Node* current, string &word, int index){
        // Base Condition: we get to the End of the Index then we Check if the "current" Node's character is the "Last Character", if YES we Return True, else if NO we Return False
        if(index==word.size()){
            return current->isLastChar;
        }

        // if Current Character's "Map (Children)" has the "word[index]" that means the Character Matches, so we go deeper to the iteration of the "DFS"
        if(current->Map.find(word[index]) != current->Map.end()){
            current = current->Map[word[index]];
            return dfs(current, word, index+1);
        }

        // if Current Character is '.'
        else if(word[index]=='.'){
            for (auto& pair : current->Map) {
                char key = pair.first;         // the character key
                Node* nextNode = pair.second;  // the Node* value

                // Each of the "nextNode" will Act as the "Current" of that DFS
                bool flag = dfs(nextNode, word, index+1);
                
                // if One of the Return Value is "true", we return "true"
                if(flag==true) {
                    return true;
                }
            }

            // that means after traversing "." Characters in DFS path, we didn't find any Matching Character
            return false;
        }

        // that means NO Character Matches so we Return "false"
        else{
            return false;
        }
    }

    void addWord(string word) {
        Node* current = root;

        for(int i=0; i<word.size(); i++){
            if(current->Map.find(word[i]) == current->Map.end()){
                current->Map[word[i]] = new Node();
            }

            current = current->Map[word[i]];
        }

        current->isLastChar=true;
    }
    
    bool search(string word) {
        Node* current = root;
        
        return dfs(current, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */