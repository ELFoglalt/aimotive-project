#include <io.h>
#include <config.h>
#include <neuralnet.h>

#include <iostream>
#include <sstream>


int main(const int argc, const char* argv[]) {

    std::vector<nn::Num> input;
    try {
        input = nn::ParseInput(argc, argv);
    } catch (const std::runtime_error e ) {
        std::cout << "Failed to parse inputs: "
                  << e.what() << "\n";

        return 1;
    }
    
    const nn::NeuralNet net(config::network);

    std::vector<nn::Num> result;
    
    try {
        result = net.apply(input);
    } catch (const std::runtime_error e) {
        std::cout << "Invalid number of input arguments: "
                  << net.input_size()
                  << " expected, "
                  << input.size()
                  << " given.\n";

        return 1;  
    }

    std::cout << nn::FormatOutput(input, result);
    
	return 0;
}