#include<vector>
class CustomStack {
    vector<int> nums;
    vector<int> increments; 
    int top=-1;
    int maxSize;
public:
    CustomStack(int maxSize) : maxSize(maxSize), top(-1), nums(maxSize), increments(maxSize, 0) {}

    
    void push(int x) {
        
        if(top<maxSize-1){
        
            nums[++top]=x;

        }
    }
    
    int pop() {
        if(top<0){
            return -1;
        }
        else{
            int value = nums[top] + increments[top];
            if (top > 0) {
                increments[top - 1] += increments[top]; // Carry over any increment
            }
            increments[top] = 0; // Reset increment for the popped element
            --top; // Decrement top
            return value; // Return the value
        }
    }
    
    void increment(int k, int val) {
        if (top >= 0) {
            increments[min(k - 1, top)] += val; // Increment the k-th element efficiently
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
