# prefixes

### TL;DR

This repo contains simple IP address prefix management implementation. It allows adding, removing and querying DB for smallest prefix given IP address.

## What's inside

In this repo you will find prefixes implementation (`prefixes.c`, `prefixes.h`) alongside tests (`main.c`).

## Build tests and run

- Simply open project directory in CLion, specify toolchain paths under __Build, Execution, Deployment > Toolchains__ menu in IDE settings and run
- Or you can build manually:
   - cd into source directory, build source and run:
```
mkdir build
cd build
cmake ..
cmake --build
./prefixes
```

