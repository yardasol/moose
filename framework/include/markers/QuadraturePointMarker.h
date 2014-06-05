/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef QUADRATUREPOINTMARKER_H
#define QUADRATUREPOINTMARKER_H

#include "Marker.h"
#include "Coupleable.h"
#include "MaterialPropertyInterface.h"

// libmesh includes
#include "libmesh/mesh_tools.h"

class QuadraturePointMarker;

template<>
InputParameters validParams<QuadraturePointMarker>();

class QuadraturePointMarker :
  public Marker,
  public Coupleable,
  public MaterialPropertyInterface
{
public:
  QuadraturePointMarker(const std::string & name, InputParameters parameters);
  virtual ~QuadraturePointMarker(){};

protected:

  virtual MarkerValue computeElementMarker();

  /**
   * Override this to compute a marker value at each quadrature point.
   *
   * The ultimate value for the element will be taken as the maximum
   * (most conservative) value for all quadrature points on the element.
   *
   * @return The MarkerValue at one quadrature point.
   */
  virtual MarkerValue computeQpMarker() = 0;

  /// The quadrature rule for the system
  QBase * & _qrule;

  /// The current quadrature point
  unsigned int _qp;
};

#endif /* QUADRATUREPOINTMARKER_H */
