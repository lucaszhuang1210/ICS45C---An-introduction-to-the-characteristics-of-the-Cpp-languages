#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template <typename T>
class Matrix
{
public:
    Matrix() : rows(0), cols(0), data{rows}
    {
        for (int i=0; i<rows; ++i)
            data[i] = Array<T> {cols};
    }

    Matrix(int rows, int cols) : rows(rows), cols(cols), data{rows}
    {
        for (int i=0; i<rows; ++i)
            data[i] = Array<T> {cols};
    }

    Array<T>& operator[] (int row) { return data[row]; }

    const Array<T>& operator[] (int row) const { return data[row]; }

    int num_rows() const { return rows; }
    int num_cols() const { return cols; }

    void fill(const T& val)
    {
        for (int i=0; i<rows; ++i)
            data[i].fill(val);
    }

    template <typename Fn>
    void fill_with_fn(Fn fn)
    {
        for (int i=0; i<rows; ++i)
            for (int j=0; j<cols; ++j)
                data[i][j] = fn(i, j);
    }

private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
    for (int i=0; i<matrix.num_rows(); ++i)
        out << matrix[i] << std::endl;
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix)
{
    int rows = matrix.num_rows();
    int cols = matrix.num_cols();
    for (int i=0; i<rows; ++i)
        for (int j=0; j<cols; ++j)
        {
            T temp;
            in >> temp;
            matrix[i][j] = temp;
        }
    return in;
}

#endif
