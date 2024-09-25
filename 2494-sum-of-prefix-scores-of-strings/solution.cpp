
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count; // Count of words that share this prefix

    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
            current->count++; // Increment count for this prefix
        }
    }

    int getPrefixScore(const string& word) {
        TrieNode* current = root;
        int score = 0;
        for (char c : word) {
            if (current->children.find(c) != current->children.end()) {
                current = current->children[c];
                score += current->count; // Add the count for this prefix
            } else {
                break; // No further prefixes exist
            }
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        // Calculate scores for each word
        vector<int> answer;
        for (const string& word : words) {
            answer.push_back(trie.getPrefixScore(word));
        }

        return answer;
    }
};

