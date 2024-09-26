class MyCalendar {
public:
    unordered_map<int,int> arr;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(auto& val : arr){
            int a=val.first;
            int b=val.second;
            if(a<end && b>start){
                return false;
            }
            if(start<b&&end>a){
                return false;
            }
            if(a<=start&& end<=b){
                return false;
            }
            if(start<a&&b<end){
                return false;
            }
        }
        arr[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 /*


 */
