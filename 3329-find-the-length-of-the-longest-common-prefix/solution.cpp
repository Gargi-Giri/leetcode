
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& numStr) {
        TrieNode* node = root;
        for (char ch : numStr) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Insert all numbers from arr1 into the trie
        for (int num : arr1) {
            trie.insert(to_string(num));
        }

        // Find the longest common prefix with numbers from arr2
        int maxLength = 0;
        for (int num : arr2) {
            maxLength = max(maxLength, getCommonPrefixLength(trie.root, to_string(num), 0));
        }

        return maxLength;
    }

private:
    int getCommonPrefixLength(TrieNode* node, const string& numStr, int depth) {
        if (node == nullptr || depth == numStr.size()) {
            return depth;
        }

        char ch = numStr[depth];
        if (node->children.count(ch)) {
            return getCommonPrefixLength(node->children[ch], numStr, depth + 1);
        } else {
            return depth; // No more common prefix
        }
    }
};

