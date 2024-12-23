#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(int rowCount, int colCount) 
    : m_rows(rowCount), m_cols(colCount) {
    AllocateMemory();
}

Matrix::~Matrix() { 
    DeallocateMemory();
}

void Matrix::Reset(int rowCount, int colCount) {
    DeallocateMemory();  // Освобождаем старую память
    
    if (rowCount <= 0 || colCount <= 0) {
        m_rows = 0;
        m_cols = 0;
    } else {
        m_rows = rowCount;
        m_cols = colCount;
        AllocateMemory();
    }
}

int& Matrix::At(int row, int col) {
    CheckBounds(row, col);
    return elements[row][col];
}

const int& Matrix::At(int row, int col) const {
    CheckBounds(row, col);
    return elements[row][col];
}

int Matrix::GetRows() const {
    return m_rows;
}

int Matrix::GetCols() const {
    return m_cols;
}

bool Matrix::operator==(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) return false;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (elements[i][j] != otherMatrix.elements[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& otherMatrix) const {
    return !(*this == otherMatrix);
}

Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    if (m_rows != otherMatrix.m_rows || m_cols != otherMatrix.m_cols) {
        throw std::invalid_argument("Matrices dimensions do not match");
    }

    Matrix sumMatrix(m_rows, m_cols);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            sumMatrix.At(i, j) = this->At(i, j) + otherMatrix.At(i, j);
        }
    }
    return sumMatrix;
}

void Matrix::AllocateMemory() {
    if (m_rows > 0 && m_cols > 0) {
        elements = new int*[m_rows]; // Выделяем память для массива
        for (int i = 0; i < m_rows; ++i) {
            elements[i] = new int[m_cols]{0};  // Инициализация нулями
        }
    } else {
        elements = nullptr; // Указываем на nullptr, если размеры некорректны
    }
}

void Matrix::DeallocateMemory() {
    if (elements) {
        for (int i = 0; i < m_rows; ++i) {
            delete[] elements[i]; // Освобождаем каждый из массивов
        }
        delete[] elements; // Освобождаем массив
        elements = nullptr; // Устанавливаем указатель в nullptr для безопасности
    }
}

void Matrix::CheckBounds(int row, int col) const {
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
}
