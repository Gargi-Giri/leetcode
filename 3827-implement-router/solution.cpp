#include <deque>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <climits>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct Packet {
    int source;
    int destination;
    int timestamp;
    int id;
};

struct PacketHash {
    size_t operator()(const tuple<int,int,int>& key) const {
        auto h1 = hash<int>()(get<0>(key));
        auto h2 = hash<int>()(get<1>(key));
        auto h3 = hash<int>()(get<2>(key));
        return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1);
    }
};

typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> OST;

class Router {
    int memLimit;
    deque<Packet> dq;
    unordered_set<tuple<int,int,int>, PacketHash> st;
    unordered_map<int, OST> destMap;
    int globalId;
public:
    Router(int memoryLimit) : memLimit(memoryLimit), globalId(0) { }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source, destination, timestamp};
        if(st.count(key)) return false;
        if(dq.size() == memLimit) {
            Packet front = dq.front();
            dq.pop_front();
            tuple<int,int,int> fkey = {front.source, front.destination, front.timestamp};
            st.erase(fkey);
            auto it = destMap.find(front.destination);
            if(it != destMap.end()){
                it->second.erase({front.timestamp, front.id});
                if(it->second.empty())
                    destMap.erase(it);
            }
        }
        Packet newPacket = {source, destination, timestamp, globalId++};
        dq.push_back(newPacket);
        st.insert(key);
        destMap[destination].insert({timestamp, newPacket.id});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        Packet front = dq.front();
        dq.pop_front();
        tuple<int,int,int> key = {front.source, front.destination, front.timestamp};
        st.erase(key);
        auto it = destMap.find(front.destination);
        if(it != destMap.end()){
            it->second.erase({front.timestamp, front.id});
            if(it->second.empty())
                destMap.erase(it);
        }
        return {front.source, front.destination, front.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destMap.find(destination) == destMap.end()) return 0;
        OST &os = destMap[destination];
        // Count elements with timestamp < startTime
        int leftCount = os.order_of_key({startTime, -1});
        // Count elements with timestamp <= endTime
        int rightCount = os.order_of_key({endTime + 1, -1});
        return rightCount - leftCount;
    }
};

