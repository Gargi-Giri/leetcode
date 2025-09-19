#include <unordered_map>
#include <string>

class Spreadsheet {
    std::unordered_map<std::string, int> cells;
    
    int getCellValue(const std::string& cell) {
        return cells.count(cell) ? cells[cell] : 0;
    }
    
public:
    Spreadsheet(int rows) {}

    void setCell(std::string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(std::string cell) {
        cells[cell] = 0;
    }

    int getValue(std::string formula) {
        formula = formula.substr(1);
        size_t plusPos = formula.find('+');
        std::string left = formula.substr(0, plusPos);
        std::string right = formula.substr(plusPos + 1);
        
        int leftVal = isdigit(left[0]) ? std::stoi(left) : getCellValue(left);
        int rightVal = isdigit(right[0]) ? std::stoi(right) : getCellValue(right);
        
        return leftVal + rightVal;
    }
};
