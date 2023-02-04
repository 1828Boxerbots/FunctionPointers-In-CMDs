// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSub.h"

ShooterSub::ShooterSub() = default;

// This method will be called once per scheduler run
void ShooterSub::Periodic() {}

void ShooterSub::SetShoot(double speed)
{
    m_shooter.Set(speed);
}
