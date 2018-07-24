/*
 * matrixsolver.cpp
 *
 *  Created on: 2018Äê7ÔÂ17ÈÕ
 *      Author: admin
 */

#include "matrixsolver.h"
#define _matrixsolver_T

namespace std {



matrixsolver::matrixsolver(arraytype A, arraytype B)
{
	this->A = A;
	this->B = B;
	//this->A.show();
}

matrixsolver::matrixsolver( arraytype *A, arraytype *B )
{
	this->A = *A;
	this->B = *B;
}
arraytype matrixsolver::gaussMethod()
{
	uint32 row_number = this->A.getRowNumber();
	uint32 col_number  =    this->B.getColNumber();
	//this->A.show();
	//this->B.show();
	arraytype out_matrix(row_number, col_number);
	for (uint32 index = 0; index < col_number; index++)
	{
		//this->B.show();
		out_matrix.colCopy( out_matrix, \
				this->tempGaussMethod(A, this->B.getColElement(index) ), index, 0 );
		//out_matrix.show();
	}
	return out_matrix;
}

arraytype matrixsolver::inverseMethod()
{
	uint32 row_number  =    this->A.getRowNumber();
	uint32 col_number  =	this->B.getColNumber();

	arraytype out_matrix(row_number, col_number);
	for (uint32 index = 0; index < col_number; index++)
	{
		out_matrix.colCopy( out_matrix, \
				this->tempInverseMethod(  A, this->B.getColElement(index) ), index, 0 );
	}
	return out_matrix;
}

arraytype matrixsolver::luMethod()
{
	uint32 row_number =    this->A.getRowNumber();
	uint32 col_number   =    this->B.getColNumber();

	arraytype out_matrix(row_number, col_number);
	for (uint32 index = 0; index < col_number; index++)
	{
		out_matrix.colCopy( out_matrix, \
				this->tempLUMethod(  A, this->B.getColElement(index) ), index, 0 );
	}
	return out_matrix;
}

arraytype matrixsolver::gaussSidelMethod(arraytype &X, FLOAT eps)
{
	uint32 row_number = this->A.getRowNumber();
	uint32 col_number  =    this->B.getColNumber();

	arraytype out_matrix(row_number, col_number);
	for (uint32 index = 0; index < col_number; index++)
	{
		out_matrix.colCopy( out_matrix, \
				this->tempGaussSideMethod(  A, this->B.getColElement(index),
																 X.getColElement(index), eps ), 	index, 0 );
	}
	X = out_matrix;
	return out_matrix;
}

arraytype matrixsolver::jacobianMethod(arraytype &X, FLOAT eps)
{
	uint32 row_number = this->A.getRowNumber();
	uint32 col_number  =    this->B.getColNumber();

	arraytype out_matrix(row_number, col_number);
	for (uint32 index = 0; index < col_number; index++)
	{
		out_matrix.colCopy( out_matrix, \
				this->tempJacobianMethod(  A, this->B.getColElement(index),
																 X.getColElement(index), eps ), 	index, 0 );
	}
	X = out_matrix;
	return out_matrix;
}


arraytype matrixsolver::tempGaussMethod(arraytype A, arraytype b)
{
	uint32 m, n;
	m = A.getRowNumber();
	n = A.getColNumber();
	//A.show();
	//b.show();
	//printf("%d",m);
#ifdef _matrixsolver_
	print("log:m=");
	println(m);
	print("log:n=");
	println(n);
#endif

	for (uint32 index = 0; index < m - 1; index++)// main element
	{
		double max_value;
		double current_value;
		uint32 max_index  = index; // max value row  index
#ifdef _matrixsolver_
		print("log:line:");
		println(index);
#endif
		/*********************************************************************
		 *  find the max main element index value
		 *********************************************************************/
		for (uint32 current_index = index+1; current_index < m; current_index++)
		{
			max_value 		= A.getElement(    max_index, index);
			current_value 	= A.getElement(current_index, index);
			if ( current_value > max_value )
			{
				max_index = current_index;
			}
		}
		/*********************************************************************
		 *   replace the max value to the current index
		 *********************************************************************/
		if (max_index != index)
		{
			A.rowSwap( index, max_index );
			b.rowSwap( index, max_index );
		}

		/*********************************************************************
		*   change to diag matrix
		 *********************************************************************/
		FLOAT  l_value;
		for(uint32 current_index = index+1; current_index < m; current_index ++)
		{
#ifdef _matrixsolver_
			print("log:current_index: ");
			println(current_index);
			//A.show();
#endif
			if (A.getElement(current_index,index) == 0 )
				continue;
			if (A.getElement( index, index ) == 0 ) continue;
				l_value = A.getElement( current_index, index )/ \
					  A.getElement( index, index );
#ifdef _matrixsolver_
			print("log:l_value:");
			println(-l_value);
#endif
			//printf("%f\n",l_value);
			/*
			for (int col_index = index; col_index < n; col_index ++)
			{
				A.setElement(current_index, col_index, l_value* \
														A.getElement( index, col_index ));
			}*/
			//println(index);
			A.rowSwap( index, current_index, -l_value);
			//A.show();
			//b.show();
			b.rowSwap( index, current_index, -l_value);
			//b.show();
			//this->Show_Matrix(A);
			//printf("\n");
			//this->Show_Matrix(b);
		}
	//this->Show_Matrix(A);
	//this->Show_Matrix(b);
	}// end of all  change

	//A.show();
	//b.show();

	arraytype x(m,1);
	x.setElement( m-1, 0,
						b.getElement( m-1, 0) / A.getElement( m-1, m-1) );

	//x.show();
	for (int index = n-2; index >=0; index --)
	{
		double sum = 0;
		//println(index);
		for (uint32 col = index+1; col < n; col ++)
		{
			sum += A.getElement( index, col )*x.getElement( col, 0 );
		}
		//x.show();
		x.setElement( index,0 ,
				(b.getElement( index, 0) - sum) / A.getElement( index, index ) );
		//x.show();
	}
	//this->Show_Matrix(x);
	//x.show();
	return x;
}

arraytype matrixsolver::tempInverseMethod(arraytype A, arraytype b)
{
	//A.show();
	//(A.inverse()).show();
	arraytype  out_arraytype;
	out_arraytype  = (A.inverse())*b;
	return out_arraytype;
}

arraytype matrixsolver::tempLUMethod(arraytype A, arraytype b)
{
	uint32 row_number = A.getRowNumber();
	arraytype out_arraytype(row_number, 1);
	arraytype y_arraytype    (row_number, 1);
	arraytype lu_arraytype   ( row_number );
	lu_arraytype = A.luFactor();
	for ( uint32 index = 0; index < row_number; index  ++)
	{
		uint32   total = 0;
		for (uint32 col = 0; col < index; col ++)
		{
			total += lu_arraytype.getElement(index, col) * y_arraytype.getElement(col, 0)  ;
		}
		y_arraytype.setElement(index, 0,   b.getElement(index, 0)- total  );
	}

	for (int64 index = row_number-1; index >=0; index --)
	{
		uint32 total = 0;
		for (int64 col = row_number-1; col >index; col-- )
		{
			total +=  lu_arraytype.getElement(index, col) * out_arraytype.getElement(col, 0);
		}
		out_arraytype.setElement(index, 0,(y_arraytype.getElement(index, 0)- total)/\
				                       	   	lu_arraytype.getElement(index,index)  );
		//println(index);
	}
	return out_arraytype;
}

arraytype  matrixsolver::tempJacobianMethod(arraytype A, arraytype b ,
											arraytype x, FLOAT eps, uint32 cycle)
{
	uint32 		row_number 		= A.getRowNumber();
	uint32 		col_number   	= A.getColNumber();
	arraytype   temp_x 			= x;
	uint32 count = 0;
	while(true)
	{
		for (uint32 row = 0; row < row_number; row++)
		{
			FLOAT temp_value = 0;
			for (uint32 col = 0; col < row; col++)
			{
				temp_value += A.getElement(row,col) * x.getElement(col,0);
			}
			for (uint32 col = row+1; col < col_number; col++)
			{
				temp_value += A.getElement(row,col) * x.getElement(col,0);
			}
			temp_x.setElement(row,0, ( b.getElement(row,0) - temp_value ) / A.getElement(row,row) );
		}
		if ( (temp_x - x).norm(1) < eps )
		{
			x = temp_x;
			break;
		}
		if (count > cycle)
		{
			printf("count more then %d\n", cycle);
			break;
		}
		count++;
		x = temp_x;
	}
	return x;
}

arraytype matrixsolver::tempGaussSideMethod(arraytype A, arraytype b,
											arraytype x, FLOAT eps, uint32 cycle)
{
	uint32 row_number 	= A.getRowNumber();
	uint32 col_number   = A.getColNumber();
	arraytype   temp_x 	= x;
	//temp_x.show();
	uint32 count = 0;
	if (A.norm(1) > 100)
	{
		print(A.norm(1));
		println("norm less then 100 please check the data");
		return x;
	}
	while(true)
	{
		for (uint32 row = 0; row < row_number; row++)
		{
			FLOAT temp_value = 0;
			for (uint32 col = 0; col < row; col++)
			{
				temp_value += A.getElement(row,col) * x.getElement(col,0);
				//println(col);
			}
			for (uint32 col = row+1; col < col_number; col++)
			{
				//println(col);
				temp_value += A.getElement(row,col) * x.getElement(col,0);
			}
			x.setElement(row,0, ( b.getElement(row,0) - temp_value ) / A.getElement(row,row) );
		}
		//x.show();
		//println( (temp_x - x).norm(1));
		//scanf("%d",&d);
		if ( (temp_x - x).norm(1) < eps )
		{
			break;
		}
		if (count > cycle)
		{
			printf("count more then %d\n", cycle);
			break;
		}
		count++;
		temp_x = x;
	}
	return x;
}

matrixsolver::~matrixsolver() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
