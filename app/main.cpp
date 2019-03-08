#include <iostream>
#include <io.h>
#include <config.h>
#include <sstream>

int main(const int argc, const char* argv[]) {

    const std::vector<nn::Number> input = nn::ParseInput(argc, argv);

    const nn::NeuralNet net(config::network);

    std::vector<nn::Number> result;
    
    try {
        result = net.apply(input);
    } catch (const std::runtime_error e) {
        std::cout << "Invalid number of input arguments. "
                  << net.input_size()
                  << " expected, "
                  << input.size()
                  << " given.\n";

        return 1;  
    }

    std::cout << nn::FormatOutput(input, result);
    
	return 0;
}