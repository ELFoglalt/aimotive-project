# Aimotive C++ test
> A simple neral network implementation

## Configuration
To modify the implemented neural net, edit the default network in `config.h`. For details about the representation and structure of the network constant, see the definition of `nn::Network` in `neuralnet.h`.

## Design notes


## Scripts
### Build
```sh
# Build in debug mode and run tests
> ./scripts/build debug
# Run the executable
> ./build/debug/neuralnet 0.2 -0.4 0.6
```

```sh
# Build in release mode and run tests
> ./scripts/build release
# Run the executable
> ./build/release/neuralnet 0.2 -0.4 0.6
```

```sh
# Clean buld directories
> ./scripts/build clean
```

### Distribution
```sh
# Create dist folder with release mode executible and docs
> ./scripts/dist
```