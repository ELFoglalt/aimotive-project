#include <neuralnet.h>
#include <stdexcept>

namespace nn
{

    //TODO: Explain or fix: Since the neural network is defined at compile time, no run-time checks are made for it's validity.
    std::vector<double> NeuralNet::apply(const std::vector<double>& input) const
    {
        if ((int)input.size() != input_size()) {
            throw std::runtime_error("Invalid number of input parameters.");
        }

        std::vector<double> previous = input;
        std::vector<double> next;

        for (auto& weight_matrix : network) {
            const int n_outputs = weight_matrix.size();
            next = std::vector<double>(n_outputs, 0);

            for (int i = 0; i < n_outputs; ++i) {
                const std::vector<double>& input_weights = weight_matrix[i];
                const int n_inputs = input_weights.size() - 1;

                // Connections
                for (int j = 0; j < n_inputs; ++j) {
                    next[i] += previous[j] * input_weights[j];
                }
                // Bias
                next[i] += input_weights[n_inputs];

                // ReLU
                next[i] = std::max(0.0, next[i]);
            }

            previous = next;
        }        

        return next;
    }

    int NeuralNet::input_size() const {
        return network.front().front().size() - 1; // -1 due to bias term
    }

    int NeuralNet::output_size() const {
        return network.back().size();
    }

    std::string NeuralNet::visualize() const
    {
        throw std::logic_error("Implement me.");
    }

} // << nn