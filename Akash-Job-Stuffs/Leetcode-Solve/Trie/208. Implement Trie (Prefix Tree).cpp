// This "Class" Corresponds to One Single Node of the Total Trie Data Structure
class Node {
public:
    map<char, Node*> Map;
    bool isLastChar;

    Node(){
        isLastChar=false;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        // initializing Trie with a "root" Node
        root = new Node();
    }
    
    void insert(string word) {
        Node* current = root;
        
        for(int i=0;i<word.size();i++){
            // *** At First we Check if we the "character" is already in the Map
            if(current->Map.find(word[i])==current->Map.end()){
                Node* temp = new Node();
                current->Map[word[i]] = temp;
            }
            
            // we traverse to the NEXT level of Trie
            current = current->Map[word[i]];
        }

        // we have come to the End of the Word
        current->isLastChar = true;
    }
    
    bool search(string word) {
        Node* current = root;
        
        for(int i=0;i<word.size();i++){
            // Did not find the Character, so we Return FALSE
            if(current->Map.find(word[i])==current->Map.end()){
                return false;
            }
            else{
                current = current->Map[word[i]];
            }
        }

        // if the Last Node's Last Character is True that means we have Found the Word
        return current->isLastChar;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        
        for(int i=0;i<prefix.size();i++){
            // Did not find the Character, so we Return FALSE
            if(current->Map.find(prefix[i])==current->Map.end()){
                return false;
            }
            else{
                current = current->Map[prefix[i]];
            }
        }

        // Since we are Searching for Prefix we "return True" Regardless of what is Stored in "isLastChar" value
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */