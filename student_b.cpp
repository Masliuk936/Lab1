#include "shared_types.h"
#include <memory>
#include <vector>
#include <cmath>

// Студент Б реалізує метод простих ітерацій
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data)
{
    const auto& A = data->A;
    const auto& b = data->b;
    int n = static_cast<int>(b.size());

    std::vector<double> x(n, 0.0);
    std::vector<double> x_new(n, 0.0);
    int iters = 0;

    for (int k = 0; k < 50; ++k) {
        iters++;
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) sum += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        if (std::abs(x_new[0] - x[0]) < 0.001) break;
        x = x_new;
    }

    auto res = std::make_unique<Result>();
    res->solution = x_new;
    res->iterations = iters;
    res->residual_norm = 0.0;
    return res;
}