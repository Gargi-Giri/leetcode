class Node {
public:
    int count;
    set<string> keys;
    Node* prev;
    Node* next;

    Node(int c) : count(c), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    unordered_map<string, int> countMap; // Maps keys to their counts
    unordered_map<int, Node*> freqMap;    // Maps counts to nodes in the linked list
    Node* head;                             // Sentinel head
    Node* tail;                             // Sentinel tail

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void addNodeAfter(Node* newNode, Node* prevNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

public:
    AllOne() {
        head = new Node(INT_MIN); // Sentinel head
        tail = new Node(INT_MAX);  // Sentinel tail
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        int count = countMap[key];
        int newCount = count + 1;
        countMap[key] = newCount;

        if (count > 0) {
            Node* oldNode = freqMap[count];
            oldNode->keys.erase(key);
            if (oldNode->keys.empty()) {
                removeNode(oldNode);
                freqMap.erase(count);
            }
        }

        if (freqMap.find(newCount) == freqMap.end()) {
            Node* newNode = new Node(newCount);
            freqMap[newCount] = newNode;

            Node* current = head;
            while (current->next->count < newCount) {
                current = current->next;
            }
            addNodeAfter(newNode, current);
        }

        freqMap[newCount]->keys.insert(key);
    }

    void dec(string key) {
        int count = countMap[key];
        int newCount = count - 1;

        Node* node = freqMap[count];
        node->keys.erase(key);
        if (node->keys.empty()) {
            removeNode(node);
            freqMap.erase(count);
        }

        if (newCount > 0) {
            countMap[key] = newCount;
            if (freqMap.find(newCount) == freqMap.end()) {
                Node* newNode = new Node(newCount);
                freqMap[newCount] = newNode;

                Node* current = head;
                while (current->next->count < newCount) {
                    current = current->next;
                }
                addNodeAfter(newNode, current);
            }
            freqMap[newCount]->keys.insert(key);
        } else {
            countMap.erase(key);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};

// Example usage:
// AllOne* obj = new AllOne();
// obj->inc("hello");
// obj->inc("hello");
// string maxKey = obj->getMaxKey(); // "hello"
// string minKey = obj->getMinKey(); // "hello"
// obj->inc("leet");
// maxKey = obj->getMaxKey(); // "hello"
// minKey = obj->getMinKey(); // "leet"

