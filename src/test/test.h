/*
 * test.h
 *
 *  Created on: 2018Äê7ÔÂ23ÈÕ
 *      Author: admin
 */

#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include "typedef.h"
#include "test_matrix_solver.h"
#include "test_fit_method.h"
#include "test_point2d.h"

//#include "test_fit_method.h"
void testAll();




#include "point2dprocess.h"
void testPoint2DProcess				();
#include "sim32process.h"
void testSim						();
#include "matrix.h"
void testMatrixGaussMethod			();


#endif /* TEST_TEST_H_ */
