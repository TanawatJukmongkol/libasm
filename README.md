# Libasm

## About
This 42 École (programming school) project is about creating basic assembly re-write of the standard c library. as a teaching tool
for students who wants to create their own C compiler from scratch.

## Build

### Dependencies
All dependencies and setup environment are listed within the .idx directory.

### Libasm
```
make
cc -Larchive-directory -lasm program.c
```

### Tester
To run test first go into the `tester` directory.
#### build
```
make
```
#### run tests
```
./test
```
#### compile_commands.json
```
bear -- make
```
