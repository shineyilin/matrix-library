/*
 * test_matrix_solver.cpp
 *
 *  Created on: 2018Äê7ÔÂ24ÈÕ
 *      Author: admin
 */

#include "test_matrix_solver.h"
void testMatrixSolver()
{
	println(">>test matrix solver:");
	println("\t>>test matrix gauss solver:");
	testMatrixSolverGaussMethod();
	println("\t>>test matrix inverse solver:");
	testMatrixSolverInverseMethod();
	println("\t>>test matrix lu solver:");
	testMatrixSolverLuMethod();
	println("\t>>test matrix gauss sidel solver:");
	testMatrixGaussSidelMethod();
	println("\t>>test matrix jacobian solver:");
	testMatrixJacobianMethod();
}



void testMatrixSolverGaussMethod()
{
	FLOAT tem[] = {1,1,0,1,2,1,1,3,1};
	FLOAT tem2[]= {3,5,8,9,10,12};
	FLOAT *temp = tem;
	FLOAT *temp2= tem2;
	arraytype m(temp,3,3);
	arraytype b(temp2,3,2);
	//m.show();
	//b.show();
	matrixsolver T(m,b);
	T.gaussMethod().show();
}

void testMatrixSolverInverseMethod()
{
	FLOAT tem[] = {1,1,0,1,2,1,1,3,1};
	FLOAT tem2[]= {3,5,8,9,10,12};
	FLOAT *temp =  tem;
	FLOAT *temp2= tem2;
	arraytype m( temp,3,3);
	arraytype b(temp2,3,2);

//	m.show();
//	m.inverse().show();
	matrixsolver T(m,b);
	T.inverseMethod().show();
}
void testMatrixSolverLuMethod()
{
	FLOAT tem[] = {1,1,0,1,2,1,1,3,1};
	FLOAT tem2[]= {3,5,8,9,10,12};
	FLOAT *temp =  tem;
	FLOAT *temp2= tem2;
	arraytype m( temp,3,3);
	arraytype b(temp2,3,2);

//	m.show();
//	m.inverse().show();
	matrixsolver T(m,b);
	T.luMethod().show();
}

void testMatrixGaussSidelMethod()
{
	arraytype X(3,1);
	X.setElement(0,0,1);
	X.setElement(1,0,2);
	X.setElement(2,0,3);

	FLOAT tem[] = {20,2,3,1,8,1,2,-3,15};
	FLOAT tem2[]= {24,5,12,9,30,12};
	FLOAT *temp =  tem;
	FLOAT *temp2= tem2;
	arraytype m( temp,3,3);
	arraytype b(temp2,3,2);

//	m.show();
//	m.inverse().show();
	matrixsolver T(m,b);
	//X.show();
	T.gaussSidelMethod(X, 0.1).show();
}

void testMatrixJacobianMethod()
{
		arraytype X(3,1);
	X.setElement(0,0,1);
	X.setElement(1,0,2);
	X.setElement(2,0,3);

	FLOAT tem[] = {20,2,3,1,8,1,2,-3,15};
	FLOAT tem2[]= {24,5,12,9,30,12};
	FLOAT *temp =  tem;
	FLOAT *temp2= tem2;
	arraytype m( temp,3,3);
	arraytype b(temp2,3,2);

//	m.show();
//	m.inverse().show();
	matrixsolver T(m,b);
	//X.show();
	T.jacobianMethod(X, 0.1).show();
}

