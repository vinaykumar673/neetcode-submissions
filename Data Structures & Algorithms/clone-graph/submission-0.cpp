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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> old_to_new;
        return dfs(node, old_to_new);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& old_to_new) {

        if(node == nullptr) {
            return nullptr;
        }

        if(old_to_new.find(node) != old_to_new.end()) {
            return old_to_new[node];
        }

        Node* copy = new Node(node->val);
        old_to_new[node] = copy;

        for(auto& neigh : node->neighbors) {
            copy->neighbors.push_back(dfs(neigh, old_to_new));
        }

        return copy;

    }











};
