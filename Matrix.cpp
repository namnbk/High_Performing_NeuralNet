// Copyright (C) 2021 raodm@miamioh.edu

#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <cassert>
#include <vector>
#include "Matrix.h"

Matrix::Matrix(const size_t row, const size_t col, const Val initVal) :
    std::vector<Val>(row * col, initVal), numberOfRows(row) {
}

// Operator to write the matrix to a given output stream
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    // Prepare
    const size_t ROWS = matrix.height(), COLS = matrix.width();
    // Print the number of rows and columns to ease reading
    os << ROWS << " " << COLS << '\n';
    // Print each entry to the output stream.
    for (size_t row = 0; (row < ROWS); ++row) {
        for (size_t col = 0; (col < COLS); ++col) {
            os << matrix[row * COLS + col] << " ";
        }
        // Print a new line at the end of each row just to format the
        // output a bit nicely.
        os << '\n';
    }
    return os;
}

// Operator to read the matrix to a given input stream.
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    // Temporary variables to load matrix sizes
    size_t height, width;
    is >> height >> width;
    // Now initialize the destination matrix to ensure it is of the
    // correct dimension.
    matrix = Matrix(height, width);
    // Read each entry from the input stream.
    for (auto& val : matrix) {
        is >> val;
    }
    return is;
}

Matrix Matrix::dot(const Matrix& rhs) const {
    // Prepare
    const auto thisHeigth = height(), thisWidth = width();
    const auto rhsHength = rhs.height(), rhsWidth = rhs.width(); 
    // Ensure the dimensions are similar.
    assert(thisWidth == rhsHength);
    // Setup the result matrix
    const auto mLength = thisHeigth, mWidth = rhsWidth;
    Matrix result(mLength, mWidth);
    // Do the actual matrix multiplication
    for (size_t row = 0; (row < mLength); row++) {
        for (size_t col = 0; (col < mWidth); col++) {
            for (size_t i = 0; (i < thisWidth); i++) {
                result[row * mWidth + col] += (*this)[row * thisWidth + i] 
                                                * rhs[i * rhsWidth + col];
            }
        }
    }
    // Return the computed result
    return result;
}

Matrix Matrix::transpose() const {
    // If the matrix is empty, then there is nothing much to do.
    if (empty()) {
        return *this;
    }

    // Create a result matrix that will be the transpose, with width
    // and height flipped.
    Matrix result(width(), height());
    // Now copy the values creating the transpose
    for (size_t row = 0; (row < height()); row++) {
        for (size_t col = 0; (col < width()); col++) {
            result[col * height() + row] = (*this)[row * width() + col];
        }
    }
    // Return the resulting transpose.
    return result;
}

#endif
