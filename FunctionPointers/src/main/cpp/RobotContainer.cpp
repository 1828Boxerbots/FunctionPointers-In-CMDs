// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here

  //Here are 3 examples of how to use FunctionPointers
  // -Using the RightTrigger -LeftTrigger -LeftY

  // &frc::XboxController::GetLeftY
  // This will pass in the function GetLeftY as a pointer
  m_pShootCMD = new ShootCMD(&m_shooterSub, &m_Xbox, &frc::XboxController::GetRightTriggerAxis, 0.2);
  //m_pShootCMD = new ShootCMD(&m_shooterSub, &m_Xbox, &frc::XboxController::GetLeftTriggerAxis, 0.2);
  //m_pShootCMD = new ShootCMD(&m_shooterSub, &m_Xbox, &frc::XboxController::GetLeftY, 0.2);

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Setting default command of the shooterSub to out ShooterCMD
  m_shooterSub.SetDefaultCommand(*m_pShootCMD);
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
