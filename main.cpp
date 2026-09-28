#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main()
{
    // Створення єдиного спільного об'єкта вхідних даних
    auto data = std::make_shared<const InputData>(InputData{
        {{2.0, 1.0, -1.0}, {-3.0, -1.0, 2.0}, {-2.0, 1.0, 2.0}}, 
        {8.0, -11.0, -3.0}                                       
    });

    std::cout << "--- Алгоритм Студента А (Метод Гауса) ---\n";
    // Виклик власної функції та отримання результату за допомогою structured bindings
    auto resultA = calculateA(data);
    auto [valueA, iterA, errorA] = *resultA;

    std::cout << "Вектор розв'язків: ";
    for (double val : valueA) std::cout << val << " ";
    std::cout << "\nКількість операцій: " << iterA;
    std::cout << "\nНорма нев'язки: " << errorA << "\n\n";


    std::cout << "--- Алгоритм Студента Б (Метод простих ітерацій) ---\n";
    auto resultB = calculateB(data);
    auto [valueB, iterB, errorB] = *resultB;

    std::cout << "Вектор розв'язків: ";
    for (double val : valueB) std::cout << val << " ";
    std::cout << "\nКількість ітерацій: " << iterB;
    std::cout << "\nНорма нев'язки: " << errorB << "\n\n";

    return 0;
}