class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        bool flag=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.') continue;
                string rowKey="row"+to_string(i)+c;
                string colKey="col"+to_string(j)+c;
                string boxKey="box"+to_string(i/3)+"-"+to_string(j/3)+c;
                if(seen.count(rowKey)||seen.count(colKey)||seen.count(boxKey)){
                    flag=false;
                    break;
                }
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
            if(!flag) break;
        }
        return flag;
    }
};
