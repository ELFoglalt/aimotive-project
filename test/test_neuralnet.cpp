// Since net is defined at compile time, sanity checks are done as tests instead of run-time checks.

#include <iostream>
#include <neuralnet.h>
#include <cmath>
#include <limits>
#include <utility>

template<typename T>
bool floatingPointEquals(T lhs, T rhs)
{
    const T eps = std::numeric_limits<T>::epsilon();

    T a = std::fabs(lhs);
    T b = std::fabs(rhs);
    
    if (a < b) {
        std::swap(a , b);
    }
    
    return (a - b) <= a * eps * 2.0;
}

template<typename T>
bool vectorEquals(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    } 
    
    for (int i = 0; i < (int)lhs.size(); ++i) {
        if (!floatingPointEquals(lhs[i], rhs[i])) {
            return false;
        }
    }
    
    return true;
}

void validate(const nn::NeuralNet& net,
              const std::vector<nn::Number>& input,
              const std::vector<nn::Number>& solution)
{
    std::vector<nn::Number> result = net.apply(input);

    if (!vectorEquals(result, solution) ) {
        std::cout << "======================================\n";
        std::cout << "Output does not match expected values!\nInput: ";
        for (auto i = input.begin(); i != input.end(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << "\nExpected: ";
        for (auto i = solution.begin(); i != solution.end(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << "\nGot: ";
        for (auto i = result.begin(); i != result.end(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << "\n";
        std::cout << "======================================\n";

        exit(1);
    }
}

int main(const int argc, const char* argv[]) {

    std::vector<nn::Number> input, solution;

    // Test case 1: Single layer
    nn::NeuralNet net1({
        // In -> Out
        {
            { 0.500, 0.500, 0.000 },
            { 0.000, 1.000, 0.000 },
        }
    });
    input    = { 1.0, 10.0 };
    solution = { 5.5, 10.0 };

    validate(net1, input, solution);
    

    // Test case 2: Bias
    nn::NeuralNet net2({
        // In -> Out
        {
            { 0.5,  1.0 },
            { 5.0, 10.0 } 
        }
    });
    input    = { 1.0 };
    solution = { 1.5, 15.0 };

    validate(net2, input, solution);


    // Test case 3: Relu
    nn::NeuralNet net3({
        // In -> Out
        {
            { 1.0, 0.000 } 
        }
    });
    input    = { -1.0 };
    solution = {  0.0 };

    validate(net3, input, solution);


    // Test case 4: Example
    nn::NeuralNet net4({
        // In -> Hidden 1
        {
            { 0.0120, 0.0500, 0.0300, 0.0000 },
            { 0.0320, 0.0100, 0.0135, 0.0000 },
            { 0.0450, 0.0200, 0.0230, 0.0000 }
        },
        // Hidden 1 -> Out
        {
            { 0.0370, 0.0230, 0.0610, 0.0000 },
            { 0.0420, 0.0510, 0.0100, 0.0000 }
        }
    });
    input    = { 0.2, -0.4, 0.6 };
    solution = { 1.1591e-3, 7.003e-4 };

    validate(net4, input, solution);

        // Test case 5: Rounding
    nn::NeuralNet net5({
        // In -> Hidden 1
        {
            { 1e-10, 0.0000 }
        },
        // Hidden 1 -> Hidden 2
        {
            { 1e-10, 0.0000 }
        },
        // Hidden 2 -> Hidden 3
        {
            { 1e20, 0.0000 }
        }
    });
    input    = { 1.0 };
    solution = { 1.0 };

    validate(net5, input, solution);

    return 0;
}