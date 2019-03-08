/**
 ! A note on these implementations:
 * The NeuralNet class was written for a
 * neural network which is known at compile time,
 * and does not implement any sanity checks during
 * runtime. An in-formatted network will most likely
 * fail with out_of_range in deubg mode.
 * 
 * The neural net written in config.h is validated by
 * a test (test_config.cpp) upon build.
 */

#include <neuralnet.h>
#include <stdexcept>

namespace nn
{
    
    std::vector<Num> NeuralNet::apply(const std::vector<Num>& input) const
    {
        if ((int)input.size() != input_size()) {
            throw std::runtime_error("Invalid number of input parameters.");
        }

        std::vector<Num> previous = input;
        std::vector<Num> next;

        for (auto& weight_matrix : network) {
            const int n_outputs = weight_matrix.size();
            next = std::vector<Num>(n_outputs, 0);

            for (int i = 0; i < n_outputs; ++i) {
                const std::vector<Num>& input_weights = weight_matrix[i];
                const int n_inputs = input_weights.size() - 1;

                // Connections
                for (int j = 0; j < n_inputs; ++j) {
                    next[i] += previous[j] * input_weights[j];
                }
                // Bias
                next[i] += input_weights[n_inputs];

                // ReLU
                next[i] = std::max(next[i], (nn::Num)0);
            }

            previous = next;
        }        

        return next;
    }

    int NeuralNet::input_size() const {
        return network.front().front().size() - 1; // - 1 because of bias term
    }

    int NeuralNet::output_size() const {
        return network.back().size();
    }

} // << nn