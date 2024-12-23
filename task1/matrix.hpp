#pragma once

class Matrix {
public:
    Matrix(int rowCount = 0, int colCount = 0);
    ~Matrix();

    void Reset(int rowCount, int colCount);
    int& At(int row, int col);
    const int& At(int row, int col) const;

    int GetRows() const;
    int GetCols() const;
    bool operator==(const Matrix& otherMatrix) const;
    bool operator!=(const Matrix& otherMatrix) const;
    Matrix operator+(const Matrix& otherMatrix) const;

private:
    int m_rows;    // Количество строк
    int m_cols;    // Количество столбцов
    int** elements; // Динамический массив для хранения элементов матрицы

    void AllocateMemory();
    void DeallocateMemory();
    void CheckBounds(int row, int col) const;
};
