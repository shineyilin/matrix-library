/*
 * fitmethod.h
 *
 *  Created on: 2018Äê7ÔÂ17ÈÕ
 *      Author: admin
 */

#ifndef FITMETHOD_H_
#define FITMETHOD_H_
#include "point2dprocess.h"
#include "arraytype.h"
#include "matrixsolver.h"

namespace std {



enum FIT_TYPE{
	method_1, method_2
};
/*
 *
 */
class fitmethod {


public:
	fitmethod();
	fitmethod(arraytype point_list, uint32 n = 2);
	virtual ~fitmethod();
public:
	void 		initFitMethod	(arraytype point_list, uint32 n = 2);
	arraytype	startFitMethod	();

private:
	FLOAT 		calcSum			(arraytype point_list, uint32 n);
	FLOAT 		calcSum_b		(arraytype point_list, uint32 n);

	void  		getFitParam_m	();
	void 		getFitmatrix_b  ();
	void 		getFitMatrix_m	();


private:
	arraytype 	*fit_matrix  = NULL;
	arraytype   *fit_matrix_b= NULL;

	arraytype   *fit_param_m = NULL;

	arraytype 	point_list;
	uint32      row_number;
	uint32 	 	col_number;
};

} /* namespace std */

#endif /* FITMETHOD_H_ */
