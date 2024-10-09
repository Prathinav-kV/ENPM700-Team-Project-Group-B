#include <iostream>
#include "pid_controller.hpp"

int main() {
  PID pid(0.1, 0.01, 0.5, 1.0);
  std::cout << "PID Output: " << pid.calculate(100.0, 90.0) << std::endl;
  return 0;
}
