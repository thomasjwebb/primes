#pragma once

#include <vector>

class PrimeChecker
{

    std::vector<int> m_numbers;

public:

    PrimeChecker(const std::vector<int> numbers);
    std::vector<std::pair<int, bool>> calculate();
    static bool isPrime(int num);
};
