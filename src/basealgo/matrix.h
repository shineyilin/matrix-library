/*
 * matrix.h
 *
 *  Created on: 2017Äê10ÔÂ3ÈÕ
 *      Author: admin
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "typedef.h"

//#define pi 3.1415926535897932

/*
 *
 */


typedef struct matrix
{
	double **matrix_data = NULL;
	int m,n;
} matrix;

namespace std {

class mymatrix {
public:
	mymatrix();
	virtual ~mymatrix();
public:

	/******************************************************/

	matrix Initial_Matrix 	( int m, int n );//storage space
	matrix Zero_Matrix    	( int m, int n); // zero matrix
	matrix One_Matrix     	( int m,int n);
	matrix Eye_Matrix     	( int m );
	matrix Rand_Matrix    	( int m, int n );

	void Destory_Matrix		(matrix T); // release storage space
	void Show_Matrix		(matrix T);

	/*******************************************************/

	/******************************************************/
	matrix Transpotion_Matrix		( matrix T);
	matrix Add_Matrix        		( matrix T1, matrix T2);//weishuequ
	matrix Element_Multiply_Matrix 	( matrix T1, matrix T2);
	matrix Element_Div_Matrix      	( matrix T1, matrix T2);
	matrix Multiply_Matrix         	( matrix T1, matrix T2);
	matrix Constant_Multiply_Matrix	( double k, matrix T1);
	matrix Inverse_Matrix          	( matrix T);
	matrix Cofactor_Matrix			( matrix T, int m, int n);
	matrix Minus_Matrix				(matrix T1, matrix T2);

	double Value_Matrix            	( matrix T );
	void   Exchange_han				( matrix &T, int r1, int r2);
	void   Exchange_lie				( matrix &T, int r1, int r2);

	matrix Gauss_Method				( matrix A, matrix b);
};

} /* namespace std */

#endif /* MATRIX_H_ */
