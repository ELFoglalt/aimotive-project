/**
 * Test cases for malformed network in config.
 */

#include <iostream>
#include <config.h>
#include <neuralnet.h>

void fail(const char* reason) {
    std::cout << "Input neural network validation failed: " << reason << "\n";
    exit(1);
}

int main(const int argc, const char* argv[]) {
    const nn::Network& network = config::network;

    const int net_size = network.size();

    if (!net_size) {
        fail("Network contains no nodes.");
    }
    
    int prev_w = -1;
    int prev_h = -1;

    for (auto& weight_matrix : network) {
        int current_h = weight_matrix.size();
        if (current_h < 1) {
            fail("Weight matrix with no connections.");
        }

        int current_w = weight_matrix[0].size();
        if (current_w < 2) {
            fail("Neuron with no- or bias only input.");
        }
        for (int i = 1; i < (int)weight_matrix.size(); ++i) {
            if (weight_matrix[i].size() < 2) {
                fail("Neuron with no- or bias only input.");
            }       

            if ((int)weight_matrix[i].size() != current_w) {
                fail("Inconsistent number of inputs within layer.");
            }
        }

        if (prev_w != -1 && prev_h != -1) {
            if (current_w - 1 != prev_h) {
                fail("Number of layer outputs is not compatible with inputs in the following layer.");
            }
        }

        prev_w = current_w;
        prev_h = current_h;
    }

	return 0;
}