#pragma once
#include <vector>

// Спільні вхідні дані: система Ax=b
struct InputData
{
    std::vector<std::vector<double>> A; // матриця коефіцієнтів
    std::vector<double> b;              // вектор вільних членів
};

// Результат роботи алгоритму
struct Result
{
    std::vector<double> solution; // вектор розв'язків
    int iterations;               // кількість операцій/ітерацій
    double residual_norm;         // норма нев'язки
};