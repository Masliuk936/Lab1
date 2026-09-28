#include "shared_types.h"
#include <memory>

// Студент Б реалізує метод простих ітерацій
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data)
{
    return std::make_unique<Result>(); 
}