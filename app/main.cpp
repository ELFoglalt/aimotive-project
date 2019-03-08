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
                  << input.size()
                  << " expected, "
                  << net.input_size()
                  << " given.\n";
    }

    std::cout << nn::FormatOutput(result);
    
	return 0;
}