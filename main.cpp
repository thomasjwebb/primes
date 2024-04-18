#include <iostream>

#include "PrimeChecker.h"

int main()
{
    // Code to check that my prime checking logic works
    // for (int num : {1, 5, 9, 17, 200, 5003, 5004, 1683169, 5000000}) {
    //     std::cout << num << " : " << PrimeChecker::isPrime(num) << std::endl;
    // }

    const std::vector<int> numbers = {68461, 551358, 541685, 3, 1, 6842, 1683169, 483579582};
    PrimeChecker primeChecker(numbers);
    auto values = primeChecker.calculate();
    for (auto res : values) {
        std::cout << res.first << " : " << res.second << std::endl;
    }
}
