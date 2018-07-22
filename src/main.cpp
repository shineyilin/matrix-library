//============================================================================
// Name        : ²åÖµÄâºÏ.cpp
// Author      : YLG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "matrix.h"
#include "typedef.h"
#include "point2dprocess.h"
#include "sim32process.h"
#include "arraytype.h"


void testarraytype()
{
	FLOAT tem[] = {9,18,9,-27,18,45,0,-45,9,0,126,9,-27,-45,9,135};
	FLOAT *temp = tem;
	arraytype m(temp,4,4);
	m = m.luFactor();
	m.show();
}

int main() {

	//testSim();
	testarraytype();
	//testPoint2DProcess();
	//testGaussMethod();
	cout << "!!!end program!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//void testMatrix()
//{
//	matrix T;
//	mymatrix matrix_hand;
//	int m = 2,n = 3;
//	T = matrix_hand.Initial_Matrix(m,n);
//	for (int row = 0; row < m; row++)
//	{
//		for (int col = 0; col <n; col ++)
//		{
//			T.matrix_data[row][col] = 1;
//		}
//	}
//	matrix_hand.Show_Matrix(T);
//
//}

void testGaussMethod()
{
	matrix T;
	matrix b;
	matrix x;
	mymatrix  matrix_hand;
	T = matrix_hand.Initial_Matrix(3,3);
	b = matrix_hand.Initial_Matrix(3,1);
	T.matrix_data[0][0] = 1;
	T.matrix_data[0][1] = 1;
	T.matrix_data[0][2] = 1;

	T.matrix_data[1][0] =  1;
	T.matrix_data[1][1] = -1;
	T.matrix_data[1][2] =  1;

	T.matrix_data[2][0] =  4;
	T.matrix_data[2][1] = -2;
	T.matrix_data[2][2] =  1;

	b.matrix_data[0][0] = 1;
	b.matrix_data[1][0] = 2;
	b.matrix_data[2][0] = 8;

	x = matrix_hand.Gauss_Method(T,b);
	matrix_hand.Show_Matrix(x);
}


void testPoint2DProcess()
{
	point2dprocess hand;
	POINT2D_LIST point2d_list;
	POINT2D point[2];
	point[0].x = 0;
	point[0].y = 0;
	point[1].x = 6;
	point[1].y = 2;

	point2d_list.push_back	( point[0]     );
	point2d_list.push_back	( point[1]	   );
	hand.initPoint2DData  	( point2d_list );
	hand.showPoint2DData	( 			   );
	//println( hand.getInsert2DData(1) )
	hand.clearPoint2DData();
}


void testSim()
{
	POINT2D temp_node[5];
	POINT2D_LIST node_list;
	temp_node[0].x = 0;
	temp_node[0].y = -10;
	temp_node[1].x = 1;
	temp_node[1].y = -100;
	temp_node[2].x = 2;
	temp_node[2].y = 100;
	temp_node[3].x = 3;
	temp_node[3].y = 10;
	temp_node[4].x = 4;
	temp_node[4].y = 10;



	for (int index = 0; index < 5; index ++)
	{
		node_list.push_back(temp_node[index]);
	}
	sim32process sim_hand;

	sim_hand.initSimProcess(10,10,0.01,1,node_list);
	sim_hand.simRun();
}



