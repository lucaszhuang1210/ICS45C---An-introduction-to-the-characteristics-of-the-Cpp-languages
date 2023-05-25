#include <cmath>
#include <iostream>
#include <numbers>

#include "array.hpp"
#include "matrix.hpp"

using namespace std;

template <typename T>
Array<T> operator*(const Matrix<T>& mat, const Array<T>& arr)
{
    if (mat.num_cols() != arr.length())
        throw string{"Dimensions do not line up for product!"};

    Array<T> result{mat.num_rows()};

    result.fill(0);

    for (int i=0; i <mat.num_rows(); ++i)
        for (int j=0; j<mat.num_cols(); ++j)
            result[j] += mat[i][j] * arr[j];

    return result;
}

template <typename T>
T ask_for(const string& message, T value = T{})
{
    cout << message;
    cin >> value;
    return value;
}

Matrix<double> rotation_matrix(double angle)
{
    Matrix<double> result{2, 2};

    result[0][0] = cos(angle);
    result[0][1] = -sin(angle);
    result[1][0] = sin(angle);
    result[1][1] = cos(angle);
    
    return result;
}

int main()
{
    int rows = ask_for<int>("Enter number of rows of matrix: ");
    int cols = ask_for<int>("Enter number of columns of matrix: ");

    Matrix<int> mat = ask_for("Enter matrix:\n", Matrix<int>{rows, cols});
    Array<int> arr = ask_for("Enter vector: ", Array<int>{cols});

    Array<double> vec = ask_for("Enter 2-d vector: ", Array<double>{2});
    double angle = ask_for<double>("Enter angle: ");

    cout << "Rotating\n"
         << vec << "\nby " << angle << " degrees gives\n"
         << rotation_matrix(angle / 180.0 * std::numbers::pi) * vec << '\n';
}
