# Aimotive C++ test
> A simple neral network implementation by Máté Kerekes.

## Configuration
To modify the neural net, edit the `network` definition in `config.h`. For details about the representation and structure of the network constant, see the definition of `Network` in `neuralnet.h`.

> If your project does not have `config.h`, make a manual copy of `example.config.h` and name it accordingly, or alternatively, run `./script/build` to automatically generate it. `config.h` is not tracked in git to allow you changing the network without causing merge conflicts.

## Notes on embedded implementation
This is a straightforward network implementation that favours readable code and convienience over both performance and generality. There are numerous directions for improvements and omptimizations most of which depend on the needs and capabilities of the target platform.

#### Network bias
The example does not explicity mention the bias term, and I forgot to ask, so I've included it in the implementation for good measure. This might be nunnecesary generality, if the implemented network was confirmed as not requiring a bias term, the related code would obviously better be removed.

#### Network representation
I've purposefully opted to go for a simple connection-weight-matrix based approach (see details in `neuralnet.h`). Since running a network requires no interaction with individual neurons there is little point in representing them as individual classes. Neuron layers could deserve their own implementation if a wider assortment of activation functions, and more advanced input/output capabilities are required.

Nested `std::vector`s were used because of their ease of use. They can be input as neat bracket initializer lists without having to worry about size template arguments. Since they are not resized, their ovehead compared to `std::array` should be constant at worst. Alternatively a custom `Matrix*`-esque structure using static arrays could be implemented.

With an couple of orders of magnitude larger networks, the current implementation fails spectecularly on two possible fronts: the time it takes to load a net into memory could introduce such a delay that by the time propagation even begins the inputs become outdated. It's also possible that the network will not even fit into the memory of the embedded target.

#### Network streaming
To solve these problems, the network class could be implemented in a streaming manner, where only a chunks of the network is ever present in memory. Since the dependencies within the network are one directional (input -> ... -> output), the streaming implementation is completely straight forward. If the embedded target is capable of parallel operations, this could also allow pipelining i.e. loading an upcoming chunk into memory while the input is being propagated trough one already available.

#### Network trougput
In an extreme case, given a modest network size and enough hardware resources (e.g. on an FPGA), a different avenue of improvement could be pipelining across layers. This could allow a constant high troughput, with latency mainly dependent on the number of hidden layers.

#### Parallel computations
Implicitly included in the previous two points, but worth pointg out: Propagating a signal boils down to a series of dot product, which are independent within layers. Both the dot product operation, and the propagation trough a given layer can be parallelized.

#### Space complexity
The storage needs of the network depend on the average number of neurons `N`, and the number of layers `L`. Given that layers are fully connected, this can be approximated as `O(N^2 x (L+1))`.

#### Standard library
The std library was extensively used to be able to write code qickly. Past experience suggests that this convienience will often not be possible on embedded systems. Naturally if the used features/implementations happen to be non-existant (or not performant enough) on the target architecture, these would had to be replaced with custom implementations.


## Scripts
### Build
```sh
# Build in debug mode and run tests
> ./script/build debug
# Run the executable
> ./build/debug/neuralnet 0.2 -0.4 0.6
```

```sh
# Build in release mode and run tests
> ./script/build release
# Run the executable
> ./build/release/neuralnet 0.2 -0.4 0.6
```

```sh
# Clean buld directories
> ./script/build clean
```

### Distribution
```sh
# Create dist folder with release mode executible and docs
> ./script/package
```