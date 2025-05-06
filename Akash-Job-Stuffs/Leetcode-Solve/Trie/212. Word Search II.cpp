class Node{
public:
    map<char, Node*> Map;
    bool isLastChar;

    Node(){
        isLastChar = false;
    }
};


class Trie{
public:
    Node* root;

    // Constructor
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* current = root;

        for(int i=0;i<word.size();i++){
            // we Did NOT find Character
            if(current->Map.find(word[i]) == current->Map.end()){
                // we Create a New Node in Corresponding to that Character
                current->Map[word[i]] = new Node();
            }

            // to Move to the Next Node
            current = current->Map[word[i]];
        }

        // we came to the End of the Last Character that's why we assign "true"
        current->isLastChar = true;
    }

    // We Don't Need Search Function as we are implementing the Search in the Below "DFS" function
};


class Solution {
public:
    void DFS(Node* current, vector<vector<char>>& board, vector<string>& words, vector<vector<bool>>& visited, set<string> &ansSet, int i, int j, string temp){
        
        int row = board.size();
        int col = board[0].size();

        // this is a part of Backtracking... after this Recursion Call is Over we mark it as "false" at the End of the Code
        visited[i][j] = true;
        
        // this means the Next Character is in "Map"
        if(current->Map.find(board[i][j]) != current->Map.end()){
            current = current->Map[board[i][j]];
            // we our Current "char" to "temp"
            temp+=board[i][j];
            
            // that means this is the Last Character, so we put it in our "ans"
            if(current->isLastChar==true){
                ansSet.insert(temp);
            }
            
            if(i+1<row && visited[i+1][j]==false){
                DFS(current, board, words, visited, ansSet, i+1, j, temp);
            }
            if(i-1>=0 && visited[i-1][j]==false){
                DFS(current, board, words, visited, ansSet, i-1, j, temp);
            }
            if(j+1<col && visited[i][j+1]==false){
                DFS(current, board, words, visited, ansSet, i, j+1, temp);
            }
            if(j-1>=0 && visited[i][j-1]==false){
                DFS(current, board, words, visited, ansSet, i, j-1, temp);
            }
            
        }
        
        // after Recursion is Done we Simply just make the Marked Index as "false" as part of Backtracking
        visited[i][j] = false;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // N.B.: The same letter cell may not be used more than once in a word
        Trie* trie = new Trie();

        // at First we Construct the Trie with the "Query" Words
        for(int i=0;i<words.size();i++){
            trie->insert(words[i]);
        }

        int row = board.size();
        int col = board[0].size();

        // we declare it a SET, because we may obtain ONE word from the Board in Several Ways, in that we will insert the Word Only Once 
        set<string> ansSet;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // The problem can be solved by traversing the grid and performing a depth-first search (DFS) for each possible starting position and Search from Trie which consists of the "Query" Words
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                DFS(trie->root, board, words, visited, ansSet, i, j, "");
            }
        }

        // converting "set" to "vector"
        vector<string> v(ansSet.begin(), ansSet.end());

        return v;
    }
};