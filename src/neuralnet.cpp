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
    // File locals  
    namespace
    {
        // Dot product that assumes that lhs.size() == rhs.size() + 1, and rhs.back() is the bias.
        Num dotProdWBias(const std::vector<Num>& lhs, const std::vector<Num>& rhs)
        {
            Num res = rhs.back();
            const int s = lhs.size();
            for (int i = 0; i < s; ++i) {
                res += lhs[i] * rhs[i];
            }
            return res;
        }

        inline Num ReLU(const Num& i) {
            return std::max(i, (nn::Num)0);
        }
    }
    

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
                next[i] = ReLU(dotProdWBias(previous, weight_matrix[i]));
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