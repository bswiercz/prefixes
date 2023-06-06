# prefixes

### TL;DR

This repo contains simple IP address prefix management implementation, along with tests. It allows adding, removing and querying DB for IP address. Recruitment assignment

## What's inside

In this repo you will find prefixes library (`prefixes.c`, `prefixes.h`) alongside with testing program (`main_test.cc`), which includes main function. Basically when you build and run this source, you can test library implementation :)

## Build tests and run

- Simply open project directory in CLion, specify toolchain paths under __Build, Execution, Deployment > Toolchains__ menu in IDE settings and run
- Or you can build manually:

Build source:
```
cmake -S . -B cmake-build
cmake --build cmake-build
```
Run tests:
```
./cmake-build/prefixes_test
```

