class Solution {
    public:
        int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
                int sz = queries.size();
                        sort(queries.begin(), queries.end());
                                priority_queue<int> pq;
                                        priority_queue<int, vector<int>, greater<>> end;
                                                int pick = 0;
                                                        int cur = 0;
                                                                int idx = 0;
                                                                        for (int i = 0; i < nums.size(); i++) {
                                                                                    while (idx < sz && queries[idx][0] <= i) pq.push(queries[idx++][1]);
                                                                                                while (nums[i] > cur) {
                                                                                                                if (pq.size() == 0) return -1;
                                                                                                                                if (pq.top() < i) {
                                                                                                                                                    pq.pop();
                                                                                                                                                                        continue;
                                                                                                                                                                                        }
                                                                                                                                                                                                        pick += 1;
                                                                                                                                                                                                                        cur += 1;
                                                                                                                                                                                                                                        end.push(pq.top());
                                                                                                                                                                                                                                                        pq.pop();
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                while (end.size() > 0 && end.top() <= i) {
                                                                                                                                                                                                                                                                                                cur -= 1;
                                                                                                                                                                                                                                                                                                               end.pop();
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                            return sz - pick;
                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                };

