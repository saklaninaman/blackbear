/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*                       BlackBear                              */
/*                                                              */
/*           (c) 2017 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#pragma once

#include "TimeDerivative.h"

/**
 * Define the Kernel for a CoupledConvectionReactionSub operator that looks like:
 *
 * storage * delta pressure / delta t
 *
 * This first line is defining the name and inheriting from Kernel.
 */
class ConcreteLatentHeat : public TimeDerivative
{
public:
  static InputParameters validParams();
  ConcreteLatentHeat(const InputParameters & parameters);

protected:
  /**
   * Responsible for computing the residual at one quadrature point
   *
   * This should always be defined in the .C
   * @return The residual of mass accumulation of primary species concentration.
   */
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  /// Material property of porosity
  const MaterialProperty<Real> & _ca;
  const MaterialProperty<Real> & _moisture_capacity;

  /// Time derivatives of relative humidity (moisture)
  const VariableValue & _H_dot;
};
