class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int totalCells = n * n; 
        int maxPossible = maxWeight / w;  
        return min(totalCells, maxPossible);  
    }
};

