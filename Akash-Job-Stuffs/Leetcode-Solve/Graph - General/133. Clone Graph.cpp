/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*> &newNodeMap) {
        if(node==NULL){
            return NULL;
        }

        Node* newNode = new Node(node->val);
        newNodeMap[node] = newNode;

        vector<Node*> neighborsList = node->neighbors;
        vector<Node*> newNeighborsList;

        for(int i=0;i<neighborsList.size();i++) {
            // newNodeMap ---> this Keep Track which Node has been "created", if there is an entry in "newNodeMap"... that means the "node" has been visited
            if(newNodeMap.find(neighborsList[i])==newNodeMap.end()) {
                Node* tempNeighborNode = dfs(neighborsList[i], newNodeMap);
                newNeighborsList.push_back(tempNeighborNode);
            }

            //*** This Condition is used as it is an "Undirected Graph", as we have arleady visited "neighborsList[i]", that means we have ALREADY created a COPY of "neighborsList[i]", so we have to PUSH that in our "newNeighborsList" Vector
            else{
                newNeighborsList.push_back(newNodeMap[neighborsList[i]]);
            }
        }

        newNode->neighbors = newNeighborsList;

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> newNodeMap; // ** this is used to Track which "oldNode" is Mapped to which "newNode"

        return dfs(node, newNodeMap);
    }
};