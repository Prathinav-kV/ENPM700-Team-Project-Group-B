#pragma once
#include <iostream>

/**
 * @class PID
 * @brief A simple PID controller class for computing velocity adjustments.
 *
 * This class is designed to calculate a new velocity given a target setpoint and the actual velocity.
 * It contains three main components for Proportional, Integral, and Derivative control: Kp, Ki, and Kd.
 */
class PID {
public:
    /**
     * @brief Constructor for PID
     * 
     * @param kp Proportional gain
     * @param ki Integral gain
     * @param kd Derivative gain
     * @param dt Time step
     */
    PID(double kp, double ki, double kd, double dt);

    /**
     * @brief calculate the new velocity based on the setpoint and actual velocity.
     *
     * @param setpoint Desired target velocity
     * @param actual_velocity Current measured velocity
     * @return calculated velocity adjustment (stub returns a constant for now)
     */
    double calculate(double setpoint, double actual_velocity);

private:
    double _Kp;  ///< Proportional gain
    double _Ki;  ///< Integral gain
    double _Kd;  ///< Derivative gain
    double _dt;  ///< Time step
    double _prev_error;  ///< Previous error value
    double _integral;  ///< Integral term
};
