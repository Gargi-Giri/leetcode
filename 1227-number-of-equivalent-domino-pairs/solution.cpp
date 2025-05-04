class Solution {
    public:
        struct pair_hash {
            size_t operator()(const pair<int, int>& p) const {
                    return hash<int>()(p.first * 10 + p.second); 
                        }
                        };
                            int numEquivDominoPairs(vector<vector<int>>& dominoes) {
                                    unordered_map<pair<int,int>,int,pair_hash> map;
                                            int result = 0;
                                                    for(auto x : dominoes){
                                                                int a = x[0];
                                                                            int b = x[1];
                                                                                        pair<int,int> p = (a<=b)? make_pair(a,b):make_pair(b,a);
                                                                                                    result += map[p];
                                                                                                                map[p]++;
                                                                                                                        }
                                                                                                                                return result;
                                                                                                                                    }
                                                                                                                                    };

