# Miller-Rabin primality test

## Build

The project uses CMake to instrument the build process. To build the current project you can enter the following line on
your command line:

```bash
cmake -DCMAKE_BUILD_TYPE=Release -Bbuild/Release
```

Then

```bash
cmake --build build/Release
```

## Run

One single binary is going to be generated at ``build/Release``:

- **primality_test**: used to find out if a number at stdin is a prime or not with confidence of 99,999904633%

Ex:

```
./build/Release/primality_test < file_with_the_number
```

It should output 's' or 'n':

- **s**: possibly prime
- **n**: definitely composite


_Have a good one :),_

Garren