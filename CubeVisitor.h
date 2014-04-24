#ifndef __CubeVisitor_h_
#define __CubeVisitor_h_
#pragma once
#pragma message ("CubeVisitor object is defined")
#include "WoodenCube.h"
#include "MetalCube.h"
#include "WaterCube.h"
#include "FireCube.h"
#include "GoldCube.h"

class CubeVisitor
{
public:
	CubeVisitor(void);
	virtual ~CubeVisitor(void);

	void visit(WoodenCube& wC);
	void visit(MetalCube& mC);
	void visit(WaterCube& wC);
	void visit(FireCube& fC);
	void visit(GoldCube& gC);
protected:

private:

};

#endif