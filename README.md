# Test Driven Development - Group 5

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/Prathinav-kV/ENPM700-Team-Project-Group-B/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/Prathinav-kV/ENPM700-Team-Project-Group-B/graph/badge.svg?token=mrguEapNpW)](https://codecov.io/gh/Prathinav-kV/ENPM700-Team-Project-Group-B) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

# Authors
| Role / Part | Part 1                    | Part 2|
|-------------|---------------------------|-------|
| Driver   | Prathinav Karnala Venkata | Nazrin Gurbanova |
| Navigator| Sivaram Dheeraj Vishnubhotla         | Datta Lohith Gannavarapu |

# About The Project
## PID Controller

This project implements a simple *PID (Proportional-Integral-Derivative)* controller for velocity adjustments in C++. The controller calculates a control output based on the difference between a target setpoint and the actual velocity.

### Files

- *pid_controller.hpp*: Contains the class declaration for the PID, including the member variables and methods.
- *src.cpp*: Contains the implementation of the PID methods, including the constructor and the calculate() function.

### Features

- *Proportional Term (Kp)*: Calculates control based on the current error.
- *Integral Term (Ki)*: Accumulates past errors to address steady-state error.
- *Derivative Term (Kd)*: Predicts future errors by considering the rate of error change.

### Usage

1. Create an instance of the PID class by providing the Kp, Ki, Kd values, and a time step.
2. Call the calculate() method with the desired setpoint and the actual velocity to get the adjusted control output.

# Code Inspiration
https://gist.github.com/bradley219/5373998

## Overview

Simple starter C++ project with:

- CMake
- GoogleTest

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/Prathinav-kV/ENPM700-Team-Project-Group-B.git
  cd ENPM700-Team-Project-Group-B
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/pid-controller-app
# Run tests:
  cd build/; ctest; cd ..
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

## Building for code coverage 
```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```

# UML Diagram
![UML Diagram](https://github.com/Prathinav-kV/ENPM700-Team-Project-Group-B/blob/main/UML/UML%20Diagram.png?raw=true)
