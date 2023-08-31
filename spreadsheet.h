#pragma once

#include "spreadsheetCell.h"

class Spreadsheet {
public:
    int getRow() const;
    int getColumn() const;
    void addRow(int);
    void addColumn(int);
    void setCell(int, int, const std::string&);
    SpreadsheetCell* getCell(int, int) const;
private:
    SpreadsheetCell** m_table = nullptr;
    int m_count_row = 0;
    int m_count_column = 0; 
};
