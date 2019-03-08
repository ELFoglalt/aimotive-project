# Aimotive C++ test
> A simple neral network implementation.

## Design notes


## Build
### Debug
```sh
# Build in debug mode and run tests
> ./scripts/build debug
# Run the executable
> ./build/debug/neuralnet 0.2 -0.4 0.6
```

### Release
```sh
# Build in release mode and run tests
> ./scripts/build release
# Run the executable
> ./build/release/neuralnet 0.2 -0.4 0.6

# Clean buld directories
> ./scripts/build clean
```

## Distribution
```sh
# Create dist folder with executible and docs:
> ./scripts/dist
```