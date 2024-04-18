#include "PrimeChecker.h"
#include <iostream>
#include <mutex>
#include <thread>

PrimeChecker::PrimeChecker(const std::vector<int> numbers)
: m_numbers(numbers)
{
}

std::vector<std::pair<int, bool>> PrimeChecker::calculate()
{
    auto it = m_numbers.begin();
    std::mutex itMutex;

    std::vector<std::thread> threads;
    std::vector<std::pair<int, bool>> primeValues;
    std::mutex primeValuesMutex;
    for (size_t i = 0; i < 2; ++i) {
        threads.emplace_back([&itMutex, &it, &primeValues, &primeValuesMutex, this]() {
            while (true) {
                int num = 0;
                {
                    std::lock_guard<std::mutex> lock(itMutex);
                    if (it == m_numbers.end()) return;
                    num = *it;
                    it++;
                }
                bool res = isPrime(num);
                {
                    std::lock_guard<std::mutex> lock(primeValuesMutex);
                    primeValues.push_back(std::make_pair(num, res));
                }
            }
        });
    }

    for (auto &t : threads)
        t.join();

    return primeValues;
}

bool PrimeChecker::isPrime(int num)
{
    if (num < 0) return false;
    if (num < 4) return true;
    for (int i = 2; i < num; ++i) {
        if (i * i > num) break;
        if (num % i == 0) return false;
    }
    return true;
}