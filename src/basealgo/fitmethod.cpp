/*
 * fitmethod.cpp
 *
 *  Created on: 2018Äê7ÔÂ17ÈÕ
 *      Author: admin
 */

#include "fitmethod.h"

namespace std {

fitmethod::fitmethod() {
	// TODO Auto-generated constructor stub
	this->row_number  = 0;
	this->col_number  = 0;
	this->fit_matrix  = new arraytype(0,0);
	this->fit_matrix_b= new arraytype(0,0);
	this->fit_param_m = new arraytype(0,0);
}

fitmethod::fitmethod(arraytype point_list, uint32 n)
{
	this->point_list = point_list;
	this->row_number = n;
	this->col_number = n;
	this->fit_matrix  = new arraytype(n,n);
	this->fit_matrix_b= new arraytype(n,1);
	this->fit_param_m = new arraytype(1,(col_number - 1)*2 + 1);
}



void fitmethod::initFitMethod(arraytype point_list, uint32 n)
{
	this->point_list  = point_list;
	this->row_number  = n;
	this->col_number  = n;
	this->fit_matrix  = new arraytype(n,n);
	this->fit_matrix_b= new arraytype(n,1);
	this->fit_param_m = new arraytype(1,(col_number - 1)*2 + 1);
}


FLOAT fitmethod::calcSum(arraytype point_list, uint32 n)
{
	uint32 col_number = point_list.getColNumber();
	FLOAT total = 0;
	for (uint32 index = 0; index < col_number; index++)
	{
		total += pow(point_list.getElement(index,0), n);
	}
	return total;
}

FLOAT fitmethod::calcSum_b(arraytype point_list, uint32 n)
{
	uint32 col_number = point_list.getColNumber();
	FLOAT total = 0;
	for (uint32 index = 0; index < col_number; index++)
	{
		total += pow(point_list.getElement(index,0), n)*\
					 point_list.getElement(index,0);
	}
	return total;
}

void fitmethod::getFitParam_m()
{
	uint32 col_number = this->fit_param_m->getColNumber();
	for (uint32 index = 0; index < col_number; index++)
	{
		fit_param_m->setElement(0,index,
				this->calcSum(this->point_list,index) );
	}
}

void fitmethod::getFitmatrix_b()
{
	uint32 row_number = this->fit_matrix_b->getRowNumber();
	for (uint32 index = 0; index < row_number; index++)
	{
		fit_matrix_b->setElement(index,0,
				this->calcSum_b(this->point_list,index) );
	}
}

void fitmethod::getFitMatrix_m()
{
	this->getFitParam_m();
	for (uint32 row = 0; row < row_number; row++)
	{
		for (uint32 col = 0; col < col_number; col++)
		{
			this->fit_matrix->setElement(row, col,
					fit_param_m->getElement(0, col+row)  );
		}
	}
}

arraytype fitmethod::startFitMethod()
{
	arraytype fit_param;
	getFitmatrix_b  ();
	getFitMatrix_m	();
	//this->fit_matrix_b->show();
	//this->fit_matrix->show();
	//printf("%d\n",this->fit_matrix->getRowNumber());
	//printf("%d\n",this->fit_matrix->getColNumber() );
	matrixsolver solver_hand(*this->fit_matrix, *this->fit_matrix_b);
	fit_param = solver_hand.gaussMethod();
	return fit_param;
}

fitmethod::~fitmethod() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
