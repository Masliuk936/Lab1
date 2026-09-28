#include "shared_types.h"
#include <memory>
#include <cmath>
#include <algorithm>

// Функція отримує спільні вхідні дані через std::shared_ptr<const InputData>
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data)
{
    // Результат повертається через std::unique_ptr<Result>
    auto result = std::make_unique<Result>();
    result->iterations = 0;

    int n = data->A.size();
    std::vector<std::vector<double>> A = data->A;
    std::vector<double> b = data->b;

    // Прямий хід методу Гауса
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
                result->iterations++;
            }
            b[j] -= factor * b[i];
            result->iterations++;
        }
    }

    // Зворотний хід
    result->solution.assign(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        result->solution[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            result->solution[i] -= A[i][j] * result->solution[j];
            result->iterations++;
        }
        result->solution[i] /= A[i][i];
        result->iterations++;
    }

    // Обчислення норми нев'язки
    result->residual_norm = 0.0;
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += data->A[i][j] * result->solution[j];
        }
        result->residual_norm = std::max(result->residual_norm, std::abs(sum - data->b[i]));
    }

    return result;
}