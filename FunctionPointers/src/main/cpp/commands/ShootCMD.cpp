// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCMD.h"

ShootCMD::ShootCMD(ShooterSub *pShooter, frc::XboxController *pXbox, double (frc::XboxController::*pInput)() const, double scale)
{
  // Set member variables to their constructor counter-parts
  m_pShooter = pShooter;
  m_pXbox = pXbox;
    //m_pInput and pInput are of same type so you can set m_pInput to pInput
    //The const in both variables are for identifying the function being passed in the variables themselves are not constants
  m_pInput = pInput;
  m_scale = scale;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pShooter);
}

// Called when the command is initially scheduled.
void ShootCMD::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootCMD::Execute()
{
  // Inside of our m_pXbox obj call function we passed in as pInput and save it into a variable
  // Place * to not look at the address of m_pInput
  double speed = (m_pXbox->*m_pInput)();

  // Use speed in the shooter
  m_pShooter->SetShoot(speed * m_scale);
}

// Called once the command ends or is interrupted.
void ShootCMD::End(bool interrupted)
{
  m_pShooter->SetShoot(0.0);
}

// Returns true when the command should end.
bool ShootCMD::IsFinished()
{
  return false;
}
