#pragma once

#include <iostream>
#include <string>

class SpreadsheetCell{
public:
    SpreadsheetCell(const std::string& = "");
    SpreadsheetCell& operator=(const SpreadsheetCell&);
    SpreadsheetCell& operator=(SpreadsheetCell&&);
    int getIntValue() const;
    double getDoubleValue() const;
    std::string getValue() const;
    void setValue(const std::string&);
private:
    std::string m_str;
};


