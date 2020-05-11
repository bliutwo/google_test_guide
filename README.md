# Instructions for Google C++ Testing and Mocking (For Dummies), Unix Edition

Keywords: quickstart, quick, start, dummies, easy, guide, test, mock, google

## Motivation

Although the [Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md#googletest-primer) and the [Googletest README](https://github.com/google/googletest/blob/master/googletest/README.md#incorporating-into-an-existing-cmake-project) are enlightening and informative, they don't contain a step-by-step, "quick start" guide to incorporating the Google C++ testing or mocking frameworks into an existing project. Hopefully, this repository can help people get quickly started with it.

**NOTE**: If there are any problems or inaccurate information in this guide, please [submit an issue](https://github.com/bliutwo/google_test_guide/issues/new/choose)!

## Generalized Instructions

Here are some steps for incorporating Google Unit Testing (or Mocking) into a basic project:

1. Modify your source file to include the following header (for example, in `tests.cc`):
   
   ```cpp
   #include "gtest/gtest.h"
   ```
   
   Similarly, for mocking, include this:

   ```cpp
   #include "gmock/gmock.h"
   ```

   **Additional setup for mocking:** Make sure to add `::testing::InitGoogleMock(&argc, argv)` to your `main()` function as such:

   ```cpp
   int main(int argc, char** argv) {
       ::testing::InitGoogleMock(&argc, argv);
       // Unit test as usual, Google Mock is initialized
   }
   ```

   And, if you want Google Mock to throw an exception when some mock-related assertion fails, add `::testing::GTEST_FLAG(throw_on_failure) = true;` as such:

   ```cpp
   int main(int argc, char** argv) {
       ::testing::GTEST_FLAG(throw_on_failure) = true;
       ::testing::InitGoogleMock(&argc, argv);
       // Unit test as usual, Google Mock is initialized
   }
   ```

2. Download these two files to the same directory as your source file:
   - [`CMakeLists.txt`](https://raw.githubusercontent.com/bliutwo/google_test_guide/master/CMakeLists.txt)
   - [`CMakeLists.txt.in`](https://raw.githubusercontent.com/bliutwo/google_test_guide/master/CMakeLists.txt.in)
   - (You can save these files by right-clicking the page and clicking `Save Page As...`)
3. In `CMakeLists.txt`, modify the last three lines to contain the executables and source files that you want. For example, if you want to make an executable called `runtests`, and your source file is `tests.cc`, you can change the last lines in `CMakeLists.txt` from this:

   ```cmake
   # Now simply link against gtest or gtest_main as needed. Eg
   add_executable(example example.cpp)
   target_link_libraries(example gtest_main)
   add_test(NAME example_test COMMAND example)
   ```
   
   to this, for **testing**:
   
   ```cmake
   # Now simply link against gtest or gtest_main as needed. Eg
   add_executable(runtests tests.cc)
   target_link_libraries(runtests gtest_main) # NOTE: gtest_main, NOT gmock_main!
   add_test(NAME example_test COMMAND runtests)
   ```

   Similarly, for **mocking**, you can change it to this:

   ```cmake
   # Now simply link against gtest or gtest_main as needed. Eg
   add_executable(runtests tests.cc)
   target_link_libraries(runtests gmock_main) # NOTE: gmock_main, NOT gtest_main!
   add_test(NAME example_test COMMAND runtests)
   ```

   You can also link both libraries in the same file:

   ```cmake
   # Now simply link against gtest or gtest_main as needed. Eg
   add_executable(runtests tests.cc)
   target_link_libraries(runtests gtest_main gmock_main) # NOTE: one line!
   add_test(NAME example_test COMMAND runtests)
   ```


4. Once you've done that, you can run the following commands (requires [`cmake`](https://cmake.org/) and [`make`](https://wiki.ubuntu.com/ubuntu-make)):
   
   ```bash
   $ cmake .
   ```
   
   ```bash
   $ make
   ```
   
   If your executable were `runtests` as mentioned above, you can run:
   
   ```bash
   $ ./runtests
   ```

That's it! I wish somewhere it was said to do that when I was figuring this out, so hopefully this can serve that purpose for others.

## Running the example test from this repository

The commands for running the example code in this directory are the following:

```bash
$ cmake .
```

```bash
$ make
```

```bash
$ ./example
```

## More examples

All of the following are from Josh Lospinoso's [C++ Crash Course: A Fast-Paced Introduction](https://smile.amazon.com/C-Crash-Course-Josh-Lospinoso/dp/1593278888):

- [Google Test example](https://github.com/bliutwo/cpp_crash_course/blob/master/ch10/google_test.cc)
- [Google Mock example](https://github.com/bliutwo/cpp_crash_course/blob/master/ch10/google_mock.cc) (In progress...)
