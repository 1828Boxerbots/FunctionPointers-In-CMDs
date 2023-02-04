// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/XboxController.h>
#include "subsystems/ShooterSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShootCMD
    : public frc2::CommandHelper<frc2::CommandBase, ShootCMD> {
 public:
  /// @brief Constructor of the ShooterCMD
  /// @param pShooter Pointer to the shooter subsystem
  /// @param pXbox Pointer to the controller the action will be on
  /// @param pInput Pointer to the function of the controller - Functions in frc::XboxController are const so place const to have consistant type
  /// @param scale Scale factor the shooter
  ShootCMD(ShooterSub* pShooter, frc::XboxController* pXbox, double (frc::XboxController::*pInput)() const, double scale = 1.0);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  // MEMBER VARIABLES OF CONSTRUCTOR VARIABLES

  ShooterSub* m_pShooter;
  frc::XboxController* m_pXbox;
  double m_scale;

  // Holds a function that returns a double and is a const function in frc::XboxController
  double (frc::XboxController::*m_pInput)()const;
};
