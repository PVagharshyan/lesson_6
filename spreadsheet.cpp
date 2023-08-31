#include "spreadsheet.h"
#include "spreadsheetCell.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

int Spreadsheet::getRow() const {
    return m_count_row;
}

int Spreadsheet::getColumn() const {
    return m_count_column;
}

void Spreadsheet::addRow(int row) {
    if (row <= 0) {
        throw std::runtime_error("Error: none valid row");
    }
    if (m_table == nullptr) {
        m_count_row = row;
        m_table = new SpreadsheetCell*[m_count_row];
        for (size_t i {}; i < m_count_row; ++i) {
            if (m_count_column == 0) {
                m_table[i] = nullptr;
            }
            else {
                m_table[i] = new SpreadsheetCell[m_count_column];
            }
        }
    }
    else {
        SpreadsheetCell** tmp = new SpreadsheetCell*[m_count_row + row];

        if (m_table[0] == nullptr) {
            for (size_t i {}; i < m_count_row + row; ++i) {
                tmp[i] = nullptr;
            }
        }
        else {
            for (size_t i {}; i < m_count_row + row; ++i) {
                tmp[i] = new SpreadsheetCell[m_count_column];
            }
            for (size_t i {}; i < m_count_row; ++i) {
                for (size_t j {}; j < m_count_column; ++j) {
                    tmp[i][j] = m_table[i][j];
                }
            }
        }
        for (size_t i {}; i < m_count_row; ++i) {
            delete [] m_table[i];
        }
        delete m_table;
        m_table = tmp;
        tmp = nullptr;
        m_count_row += row;
    }
}

void Spreadsheet::addColumn(int column) {
    if (column <= 0) {
        throw std::runtime_error("Error: none valid column");
    }
    if (m_table == nullptr) {
        m_count_column = column;
    }
    else {
        SpreadsheetCell** tmp = new SpreadsheetCell*[m_count_row];

        for (size_t i {}; i < m_count_row; ++i) {
            tmp[i] = new SpreadsheetCell[m_count_column + column];
        }
        for (size_t i {}; i < m_count_row; ++i) {
            for (size_t j {}; j < m_count_column; ++j) {
                tmp[i][j] = m_table[i][j];
            }
        }
        for (size_t i {}; i < m_count_row; ++i) {
            delete [] m_table[i];
        }
        delete m_table;
        m_table = tmp;
        tmp = nullptr;
        m_count_column += column;
    }
}

void Spreadsheet::setCell(int y, int x, const std::string& str) {
    if (
            (x > m_count_column || x < 0) ||
            (y > m_count_row || y < 0)
        ) {
        throw std::runtime_error("Error: none valid coordinates");
    } 
    m_table[y][x].setValue(str);
}

SpreadsheetCell* Spreadsheet::getCell(int y, int x) const {
    if (
            (x > m_count_column || x < 0) ||
            (y > m_count_row || y < 0)
        ) {
        throw std::runtime_error("Error: none valid coordinates");
    }
    return &(m_table[y][x]);
}
