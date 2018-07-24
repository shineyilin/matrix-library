/*
 * matrix.cpp
 *
 *  Created on: 2017Äê10ÔÂ3ÈÕ
 *      Author: admin
 */

#include "matrix.h"

namespace std {

mymatrix::mymatrix() {
	// TODO Auto-generated constructor stub

}

mymatrix::~mymatrix() {
	// TODO Auto-generated destructor stub
}

//#include"matrix.h"
// apply for storage space m han n lie

matrix mymatrix::Initial_Matrix ( int m, int n )
{
	register int i;
	matrix T;
	T.matrix_data = (double **)malloc(m*sizeof(double *));
 	for ( i = 0; i < m; i ++ )
	{
		T.matrix_data[i] = NULL;
		T.matrix_data[i] = (double *)malloc(n*sizeof(double));
	}
	T.m = m;
	T.n = n;
	return T;
}
// zero matrix
matrix mymatrix::Zero_Matrix( int m, int n)
{
	matrix T;
	T = Initial_Matrix(m,n);
	for ( register int i = 0; i < m; i++ )
	{
		for ( register int j = 0; j < n; j++ )
		{
			T.matrix_data[i][j] = 0;
		}
	}
	return T;
}

matrix mymatrix::One_Matrix( int m, int n)
{
	matrix T;
	T = Initial_Matrix(m,n);
	for ( register int i = 0; i < m; i++ )
	{
		for ( register int j = 0; j < n; j++ )
		{
			T.matrix_data[i][j] = 1;
		}
	}
	return T;
}

matrix mymatrix::Eye_Matrix( int m)
{
	matrix T;
	T = Initial_Matrix(m,m);
	for ( register int i = 0; i < m; i++ )
	{
		for ( register int j = 0; j < m; j++ )
		{
			if (i == j) T.matrix_data[i][j] = 1;
			else T.matrix_data[i][j] = 0;
		}
	}
	return T;
}

matrix mymatrix::Rand_Matrix( int m, int n )
{
	srand(time(NULL));  // init rand number
	matrix T;
	T = Initial_Matrix(m,n);
	for ( register int i = 0; i < m; i++ )
	{
		for ( register int j = 0; j < n; j++ )
		{
 			T.matrix_data[i][j] = rand()%10000/10000.0;
		}
	}
	return T;
}



// release storage space
void mymatrix::Destory_Matrix(matrix T)
{
	for (register int j = 0; j < T.m; j++ )
	{
 		free( T.matrix_data[j] );
		T.matrix_data[j] = NULL;
	}
	free(T.matrix_data);

}

void mymatrix::Show_Matrix(matrix T)
{
	for (register int i = 0; i < T.m; i++)
	{
		for(register int j = 0; j < T.n; j++ )
		{
			printf("%25.12f ",T.matrix_data[i][j]);
		}
		printf("\n");
	}

}
/*******************************************************/
/******************************************************************/
//	ju zheng zhuan zhi
/******************************************************************/
//#include "matrix.h"
matrix mymatrix::Transpotion_Matrix( matrix T)
{
	matrix tra_temp;
	tra_temp = Initial_Matrix(T.n, T.m);

	for ( register int i = 0; i < T.m; i++ )
	{
		for ( register int j = 0; j < T.n; j++ )
		{
			 tra_temp.matrix_data[j][i] = T.matrix_data[i][j];
		}
	}
	return tra_temp;
}

/******************************************************************/
//	ju zheng jia fa
/******************************************************************/

matrix mymatrix::Add_Matrix(matrix T1, matrix T2)
{
	matrix T;
	if (T1.m != T2.m or  T1.n != T2.n)
	{
		printf("matrix does not equal");
		return T;
	}
	T = Initial_Matrix(T1.m,T1.n);
	for (register int i = 0; i < T1.m; i++)
	for (register int j = 0; j < T1.n; j++)
	T.matrix_data[i][j]=T1.matrix_data[i][j]+T2.matrix_data[i][j];
	return T;
}
/******************************************************************/
//	ju zheng jian fa
/******************************************************************/

matrix mymatrix::Minus_Matrix(matrix T1, matrix T2)
{
	matrix T;
	if (T1.m != T2.m or  T1.n != T2.n)
	{
		printf("matrix does not equal");
		return T;
	}
	T = Initial_Matrix(T1.m,T1.n);
	for (register int i = 0; i < T1.m; i++)
	for(register int j = 0; j < T1.n; j++)
	T.matrix_data[i][j]=T1.matrix_data[i][j]-T2.matrix_data[i][j];
	return T;
}

/******************************************************************/
//	ju zheng yuan shu cheng fa
/******************************************************************/

matrix mymatrix::Element_Multiply_Matrix(matrix T1, matrix T2)
{
	matrix T;
	if (T1.m != T2.m or  T1.n != T2.n)
	{
		printf("matrix does not equal");
		return T;
	}
	T = Initial_Matrix(T1.m,T1.n);
	for (register int i = 0; i < T1.m; i++)
	for(register int j = 0; j < T1.n; j++)
	T.matrix_data[i][j]=T1.matrix_data[i][j]*T2.matrix_data[i][j];
	return T;
}
/******************************************************************/
//	ju zhen yuan shu chu fa
/******************************************************************/

matrix mymatrix::Element_Div_Matrix(matrix T1, matrix T2)
{
	matrix T;
	if (T1.m != T2.m or  T1.n != T2.n)
	{
		printf("matrix does not equal");
		return T;
	}
	T = Initial_Matrix(T1.m,T1.n);
	for (register int i = 0; i < T1.m; i++)
	for(register int j = 0; j < T1.n; j++)
	T.matrix_data[i][j]=T1.matrix_data[i][j]/T2.matrix_data[i][j];
	return T;
}
/******************************************************************/
//	ju zhen cheng fa T1.m = T2.n
/******************************************************************/

matrix mymatrix::Multiply_Matrix(matrix T1, matrix T2)
{
	matrix T;
	if (T1.n != T2.m)
	{
		printf("matrix does not equal");
		return T;
	}
	T = Initial_Matrix(T1.m,T2.n);
	double temp;
	for (register int i = 0; i < T1.m; i++)
	for( register int j = 0; j < T2.n; j++)
	{
		temp = 0;
		for( register int k = 0; k < T1.n; k++ )
		{
			temp += T1.matrix_data[i][k] * T2.matrix_data[k][j];
		}
		T.matrix_data[i][j]=temp;
	}
	return T;
}
/******************************************************************/
//	ju zhen cheng fa, chan liang chen ju z
/******************************************************************/

matrix mymatrix::Constant_Multiply_Matrix(double k, matrix T1)
{
	matrix T;
	T = Initial_Matrix(T1.m,T1.n);

	for (register int i = 0; i < T1.m; i++)
	for (register int j = 0; j < T1.n; j++)
	T.matrix_data[i][j] = k * T1.matrix_data[i][j];
	return T;
}
/******************************************************************/
//	jiao huang liang hang
/******************************************************************/
void mymatrix::Exchange_han(matrix &T,int r1, int r2)
{
	double *temp = NULL;
	temp = T.matrix_data[r1];
	T.matrix_data[r1] = T.matrix_data[r2];
	T.matrix_data[r2] = temp;
}
/******************************************************************/
//	jiao huang liang lie
/******************************************************************/

void mymatrix::Exchange_lie(matrix &T,int r1, int r2)
{
	double temp[T.m];
	register int i;
	for(i=0; i < T.m; i++) temp[i] = T.matrix_data[i][r1];
	for(i=0; i<T.m;i++) T.matrix_data[i][r1] = T.matrix_data[i][r2];
	for( i = 0; i < T.m; i++) T.matrix_data[i][r2] = temp[i];
}


/******************************************************************/
//	ju zhen hang lue shi zhi
/******************************************************************/
double mymatrix::Value_Matrix(matrix T)
{
	if (T.m != T.n)
	{
		printf("can not get matrix value!!");
		return 0;
	}
	matrix temp = Initial_Matrix(T.m, T.n);
	double value = 1;
	double c;
	register int i;
	register int j;

	for (i = 0; i < T.m; i++)
	for (j = 0; j < T.n; j++ )
		temp.matrix_data[i][j] = T.matrix_data[i][j];

	for (register int k = 0; k < T.m; k++)
	{
		//printf("%d\n",k);
		if (temp.matrix_data[k][k] == 0 and k != T.m-1)
			for (register int p = 1; p<T.m; p++)
			{
				Exchange_han(temp,k,k+p);
				if (temp.matrix_data[k][k] != 0 ) break;
			}
		for (i = k + 1; i < T.m; i++)
		{
			c = -1*temp.matrix_data[i][k] / temp.matrix_data[k][k];
			for (j = k; j < T.n; j++ )
				temp.matrix_data[i][j]=	    temp.matrix_data[i][j] +
										c * temp.matrix_data[k][j];
		}
	}

	//Show_Matrix(temp);
	for (i = 0; i < T.m; i++)
	for (j = 0; j < T.n; j++)
		if (i == j) value *= temp.matrix_data[i][j];
	Destory_Matrix(temp);
	return value;
}
/******************************************************************/
//	dai su yu zhi shi
/******************************************************************/
matrix mymatrix::Cofactor_Matrix(matrix T, int m, int n)
{
	matrix cof = Initial_Matrix(T.m -1, T.n -1);
	for (register int i = 0; i < T.m; i++)
	for (register int j = 0; j < T.n; j++)
	{
		if(i < m and j < n)
			cof.matrix_data[i][j]   = T.matrix_data[i][j];
		if(i < m and j > n)
			cof.matrix_data[i][j-1] = T.matrix_data[i][j];
		if(i > m and j < n)
			cof.matrix_data[i-1][j] = T.matrix_data[i][j];
		if(i > m and j > n)
			cof.matrix_data[i-1][j-1]=T.matrix_data[i][j];

	}
	//Show_Matrix(cof);
	return cof;
}

/******************************************************************/
//	ju zhen de ni
/******************************************************************/
matrix mymatrix::Inverse_Matrix(matrix T)
{
	int c;
	double abs_a = Value_Matrix(T);
	matrix inv = Initial_Matrix(T.m, T.n);
	matrix tmp;

	for (register int i = 0; i < T.m; i++)
	for (register int j = 0; j < T.n; j++)
	{
		c   = pow(-1, (i+1)+(j+1) );
		tmp = Cofactor_Matrix(T,i,j);
		//printf("%f\n",1*Value_Matrix(tmp));
 		inv.matrix_data[j][i] = c * Value_Matrix(tmp);
		inv.matrix_data[j][i] = inv.matrix_data[j][i]/abs_a;
		Destory_Matrix(tmp);
	};
	return  inv;
}

/******************************************************************/
//	gauss direct solve
/******************************************************************/
matrix mymatrix::Gauss_Method(matrix A, matrix b)
{
	int m, n;
	m = A.m;
	n = A.n;

	//printf("%d",m);
	for (int index = 0; index < m - 1; index++)// main element
	{
		double max_value;
		double current_value;
		int max_index  = index; // max value row  index

		/*********************************************************************
		 *  find the max main element index value
		 *********************************************************************/
		for (int current_index = index+1; current_index < m; current_index++)
		{
			max_value 		= A.matrix_data[max_index][index];
			current_value 	= A.matrix_data[current_index][index];
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
			double *temp_pointer	= NULL;
			temp_pointer 			= A.matrix_data[index];
			A.matrix_data[index] 	= A.matrix_data[max_index];
			A.matrix_data[max_index]= temp_pointer;

			temp_pointer   			= b.matrix_data[index];
			b.matrix_data[index]    = b.matrix_data[max_index];
			b.matrix_data[max_index]= temp_pointer;
		}
		//this->Show_Matrix(A);

		/*********************************************************************
		*   change to diag matrix
		 *********************************************************************/
		double l_value;
		for(int current_index = index+1; current_index < m; current_index ++)
		{
			if (A.matrix_data[index][index] == 0 ) continue;
			l_value = A.matrix_data[current_index][index]/ \
					  A.matrix_data[index][index];
			//printf("%f\n",l_value);
			for (int col_index = index; col_index < n; col_index ++)
			{
				A.matrix_data[current_index][col_index] -= l_value* \
						A.matrix_data[index][col_index];
			}
			b.matrix_data[current_index][0] -= l_value* \
								b.matrix_data[index][0];
			//this->Show_Matrix(A);
			//printf("\n");
			//this->Show_Matrix(b);

		}
	//this->Show_Matrix(A);
	//this->Show_Matrix(b);
	}// end of all  change

	matrix x;
	x 					  = this->Initial_Matrix(m,1);
	x.matrix_data[m-1][0] = b.matrix_data[m-1][0]/A.matrix_data[m-1][m-1];
	for (int index = n-2; index >=0; index --)
	{
		double sum = 0;
		for (int col = index+1; col < n; col ++)
		{
			sum += A.matrix_data[index][col]*x.matrix_data[col][0];
		}
		x.matrix_data[index][0] = (b.matrix_data[index][0]-sum)/\
									A.matrix_data[index][index];
	}
	//this->Show_Matrix(x);
	return x;
}






} /* namespace std */
