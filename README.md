# Aimotive C++ test

## Building
### Debug
```sh
# Build
> mkdir -p ./build/debug
> cd ./build/debug
> cmake -DCMAKE_BUILD_TYPE=Debug ../.. && make
# Run
> ./neuralnet
```

### Release
```sh
# Build
> mkdir -p ./build/release
> cd ./build/release
> cmake -DCMAKE_BUILD_TYPE=Release ../.. && make
# Run
> ./neuralnet
```