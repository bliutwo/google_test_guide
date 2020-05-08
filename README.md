# Instructions for Google C++ Testing (For Dummies), Unix Edition

Keywords: quickstart, quick, start, dummies, easy, guide

## Motivation

Although the [Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md#googletest-primer) and the [Googletest README](https://github.com/google/googletest/blob/master/googletest/README.md#incorporating-into-an-existing-cmake-project) are enlightening and informative, they don't contain a step-by-step, "quick start" guide to incorporating the Google C++ testing framework into an existing project. Hopefully, this repository can help people get quickly started with it.

## Generalized Instructions

Here are some steps for incorporating Google Unit Testing into a basic project:

1. Download these two files to the directory that has your source code:
   - [`CMakeLists.txt`]()
   - [`CMakeLists.txt.in`]()
2. In `CMakeLists.txt`, modify the last two lines to contain the executables and source files that you want. For example, if you want to make an executable called `runtests`, and your source file is `tests.cc`, you can change the last lines in `CMakeLists.txt` from this:

```cmake
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)
```

to this:

```cmake
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)
```

## Running the example test from this directory

The commands for running the example code in this directory are the following:

```bash
$ cmake .
```

```bash
$ make
```

That's it! I wish somewhere it was said to do that. Glad I finally
figured it out, though.

