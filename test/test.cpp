#include <gtest/gtest.h>
#include "pid_controller.hpp"

class PIDTest : public ::testing::Test {
 protected:
    double Kp = 0.1;
    double Ki = 0.02;
    double Kd = 0.8;
    double dt = 1.0;
    PID pid{Kp, Ki, Kd, dt};  // PID controller instance
};

TEST_F(PIDTest, this_will_fail) {
    double setpoint = 10.0;
    double actual_velocity = 0.0;

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_GT(output, 0.0);
}

TEST_F(PIDTest, this_will_fail_too) {
    double setpoint = 100.0;
    double actual_velocity = 80.0;

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_DOUBLE_EQ(output, 18.4);  // Proportional only for this case
}
