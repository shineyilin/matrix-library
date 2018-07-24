/*
 * matrixsolver.h
 *
 *  Created on: 2018Äê7ÔÂ17ÈÕ
 *      Author: admin
 */

#ifndef MATRIXSOLVER_H_
#define MATRIXSOLVER_H_


#include "arraytype.h"

namespace std {

/*
 *jie sheji zhong de yige you xiu de
 */
class matrixsolver  {
public:
	matrixsolver					(	);
	matrixsolver 					( arraytype  A, arraytype   B );
	matrixsolver 					( arraytype *A, arraytype *B );

	virtual ~matrixsolver			(	);
public:
	arraytype gaussMethod			(	);
	arraytype inverseMethod			(	);
	arraytype luMethod				(	);
	arraytype gaussSidelMethod		( arraytype &X, FLOAT eps );
	arraytype jacobianMethod		( arraytype &X, FLOAT eps );


public:
	arraytype tempGaussMethod		(arraytype A, arraytype b );
	arraytype tempInverseMethod		(arraytype A, arraytype b );
	arraytype tempLUMethod         	(arraytype A, arraytype b );
	arraytype tempGaussSideMethod	(arraytype A, arraytype b,
									 arraytype x, FLOAT eps, uint32 cycle = 10000);
	arraytype tempJacobianMethod  	(arraytype A, arraytype b,
									 arraytype x, FLOAT eps, uint32 cycle = 10000);

private:
	arraytype A;
	arraytype B;
};

} /* namespace std */

#endif /* MATRIXSOLVER_H_ */
