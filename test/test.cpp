#include <gtest/gtest.h>
#include "pid_controller.hpp"

class PIDTest : public ::testing::Test {
protected:
    // Example PID parameters
    double Kp = 0.1; // Proportional gain
    double Ki = 0.02; // Integral gain
    double Kd = 0.8; // Derivative gain
    double dt = 1.0; // Time step
    PID pid{Kp, Ki, Kd, dt}; // PID controller instance
};

TEST_F(PIDTest, TestInitialConditions) {
    double setpoint = 100.0;
    double actual_velocity = 0.0;
    
    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_GT(output, 0.0); // Expect a positive output since the actual is below the setpoint
}

TEST_F(PIDTest, TestProportionalControl) {
    double setpoint = 100.0;
    double actual_velocity = 80.0;

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_DOUBLE_EQ(output, 18.4); // Proportional only for this case
}

TEST_F(PIDTest, TestIntegralControl) {
    double setpoint = 100.0;
    double actual_velocity = 80.0;

    // Call calculate multiple times to simulate time
    for (int i = 0; i < 5; ++i) {
        pid.calculate(setpoint, actual_velocity);
    }

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_GT(output, Kp * (setpoint - actual_velocity)); // Expect output to increase due to integral
}

TEST_F(PIDTest, TestDerivativeControl) {
    double setpoint = 100.0;
    double actual_velocity = 80.0;

    // First call
    double first_output = pid.calculate(setpoint, actual_velocity);
    // Change in actual_velocity simulating a response
    actual_velocity = 95.0;
    double second_output = pid.calculate(setpoint, actual_velocity);

    // Expect the output to decrease as the actual velocity approaches the setpoint
    EXPECT_LT(second_output, first_output); // Expect the output to decrease
}

TEST_F(PIDTest, TestNoOutputWhenAtSetpoint) {
    double setpoint = 80.0;
    double actual_velocity = 80.0;

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_EQ(output, 0.0); // Expect no output since we're at the setpoint
}

TEST_F(PIDTest, TestNegativeSetpoint) {
    double setpoint = -60.0; // Negative target
    double actual_velocity = 0.0;

    double output = pid.calculate(setpoint, actual_velocity);
    EXPECT_LT(output, 0.0); // Expect negative output since actual is above the negative setpoint
}
