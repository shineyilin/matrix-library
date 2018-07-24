/*
 * arraytype.cpp
 *
 *  Created on: 2018Äê7ÔÂ5ÈÕ
 *      Author: admin
 */

#include "arraytype.h"

namespace std {


arraytype::arraytype()
{
	//TODO initial the total class
	this->row_number = 0;
	this->col_number   = 0;
	this->item = NULL;
}


arraytype::arraytype(int m, int n) {
	// TODO Auto-generated constructor stub
	if (m<0 or n <0)
	{
		println("Error: please check the data!!!");
		return;
	}
	this->row_number = m;
	this->col_number = n;
	item = new FLOAT[m*n];
	for (int i = 0; i < m*n; i++)
	{
		item[i] = 0;
	}
}

arraytype::arraytype(int n)
{
	if (n < 0)
	{
		println("Error: please check the data!!!");
		return;
	}
	this->row_number = n;
	this->col_number = n;
	item = new FLOAT[n*n];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (i == j) this->setElement(i,j,1);
		else 		this->setElement(i,j,0);
	}
}

arraytype::arraytype(array_type type, int m, int n)
{
	if (type == ZEROS)
	{
		if (m<0 or n <0)
		{
			println("Error: please check the data!!!");
			return;
		}
		this->row_number = m;
		this->col_number = n;
		item = new FLOAT[m*n];
		for (int i = 0; i < m*n; i++)
		{
			item[i] = 0;
		}
	}
	else if (type == ONES)
	{
		if (m<0 or n <0)
		{
			println("Error: please check the data!!!");
			return;
		}
		this->row_number = m;
		this->col_number = n;
		item = new FLOAT[m*n];
		for (int i = 0; i < m*n; i++)
		{
			item[i] = 1;
		}
	}
	else if (type == RANDS)
	{
		if (m<0 or n <0)
		{
			println("Error: please check the data!!!");
			return;
		}
		srand(time(NULL));
		this->row_number = m;
		this->col_number = n;
		item = new FLOAT[m*n];
		for (int i = 0; i < m*n; i++)
		{
			item[i] = FLOAT( rand())/RAND_MAX;
		}
	}
}

arraytype::arraytype(double *item_input, int m, int n)
{
	if (m < 0 or n < 0)
	{
		println("Error: please check the data!!!");
		return;
	}
	this->row_number = m;
	this->col_number = n;
	item = new FLOAT[m*n];
	for (int i=0; i < m*n; i ++)
	{
		item[i] = item_input[i];
	}
}

arraytype::arraytype(const arraytype &m)
{
	this->col_number = m.col_number;
	this->row_number = m.row_number;
	this->item = new FLOAT[col_number * row_number];
	for (uint32 i = 0; i < col_number * row_number; i ++)
	{
		this->item[i] = m.item[i];
	}
}

bool arraytype::fromFile(string file)
{
	MATRIX matrix_list;
	fileio file_hand(file);
	matrix_list = file_hand.readSplitDataToMatrix();
	uint32 m = matrix_list.size();
	uint32 n = matrix_list[0].size();
	this->row_number = m;
	this->col_number = n;

	this->item = new FLOAT[m*n];
	uint32 index;
	for (uint32 row = 0; row < m; row++)
	{
		for (uint32 col = 0; col < n; col ++)
		{
			index = n*row+col;
			this->item[index] = matrix_list[row][col];
		}
	}
	return true;
}

uint32 arraytype::getColNumber()
{
	return this->col_number;
}
uint32 arraytype::getRowNumber()
{
	return this->row_number;
}

arraytype arraytype::trans()
{
	arraytype tran_arraytype(this->col_number,this->row_number);
	//tran_arraytype.col_number = this->col_number;
	//tran_arraytype.row_number = this->row_number;
	for (uint32 row = 0; row < this->row_number; row++)
	{
		for (uint32 col = 0; col < this->col_number; col++)
		{
			tran_arraytype.setElement(col, row,\
					       this->getElement(row, col));
		}
	}
	return tran_arraytype;
}

FLOAT arraytype::getElement(int i, int j) const
{
	return item[i * this->col_number + j];
}
void arraytype::setElement(int i, int j, FLOAT value)
{
	item[i * this->col_number + j] = value;
}

arraytype arraytype::getRowElement(uint32 index)
{
	arraytype out_arraytype(1,this->col_number);
	for (uint32 col =0; col < this->col_number; col++)
		out_arraytype.setElement(0,col, this->getElement(index, col));
	return out_arraytype;
}
arraytype arraytype::getColElement(uint32 index)
{
	arraytype out_arraytype(this->row_number,1);
	for (uint32 row =0; row < this->row_number; row++)
		out_arraytype.setElement(row,0, this->getElement(row, index));
	return out_arraytype;

}



arraytype arraytype::operator +(const arraytype& m)
{
	if (m.col_number != this->col_number || m.row_number != this->row_number)
	{
		println("Error: please check the data again!!!");
		return *this;
	}
	arraytype out_arraytype = *this;
	for (uint32 row = 0; row < row_number; row++)
	{
		for (uint32 col = 0; col < col_number; col++)
		{
			out_arraytype.setElement(row,col,\
					this->getElement(row,col)+m.getElement(row,col));
		}
	}
	return out_arraytype;
}

arraytype arraytype::operator -(const arraytype& m)
{
	if (m.col_number != this->col_number || m.row_number != this->row_number)
	{
		println("Error: please check the data again!!!");
		return *this;
	}
	arraytype out_arraytype = *this;
	for (uint32 row = 0; row < row_number; row++)
	{
		for (uint32 col = 0; col < col_number; col++)
		{
			out_arraytype.setElement(row,col,\
					this->getElement(row,col)-m.getElement(row,col));
		}
	}
	return out_arraytype;
}

arraytype arraytype::operator *(const arraytype& m)
{
	//println(m.row_number);
	//println(this->col_number);
	if (this->col_number != m.row_number)
	{
		println("Error: not equal please check the data again!!!");
		return *this;
	}
	arraytype out_arraytype(this->row_number, m.col_number);
	for (uint32 row = 0; row < row_number; row++)
	{
		for (uint32 col = 0; col < m.col_number; col++)
		{
			FLOAT sum = 0;
			for (uint32 index = 0; index < this->col_number; index++)
			{
				sum += this->getElement(row,index)*m.getElement(index,col);
			}
			out_arraytype.setElement(row,col, sum);
		}
	}
	return out_arraytype;
}

arraytype arraytype::operator *(const FLOAT& value)
{
	arraytype out_arraytype = *this;
	for (uint32 row = 0; row < row_number; row++)
	{
		for (uint32 col = 0; col < this->col_number; col++)
		{
			out_arraytype.setElement(row,col,this->getElement(row,col)*value);
		}
	}
	return out_arraytype;
}

arraytype arraytype::operator =(const arraytype& m)
{
	row_number = m.row_number;
	col_number = m.col_number;
	item = new FLOAT[row_number*col_number];
	for (uint32 index = 0; index <row_number*col_number; index++ )
	{
		item[index] = m.item[index];
	}
	return *this;
}

inline FLOAT Abs(FLOAT x)
{
	if (x > 0) return x;
	else return -x;
}


arraytype arraytype::upTrag()
{
	arraytype out_arraytype 	= *this;
	out_arraytype.col_number 	= this->col_number;
	out_arraytype.row_number 	= this->row_number;
	for (uint32 row = 0; row < row_number; row++)
	{
		uint32 max_row_index = row;
		for (uint32 index = row+1; index < row_number; index++ )
		{
			if (Abs(this->getElement(max_row_index,row)) <\
					Abs(this->getElement(index, row)) )
			{
				max_row_index = index;
			}
		}
		if (max_row_index != row) this->rowSwap(row, max_row_index);

		FLOAT l_value;
		for (uint32 index = row+1; index< row_number; index++)
		{
			l_value = -1* this->getElement(index,row)/this->getElement(row,row);
			this->rowSwap(row,index,l_value);
		}
	}
	return out_arraytype;
}


void arraytype::rowSwap(uint32 row1, uint32 row2, FLOAT factor) // i*factor + j
{
	for (uint32 index = 0; index < this->col_number; index++)
	{
		this->setElement(row2,index, \
		  this->getElement(row1,index)*factor + this->getElement(row2,index));
	}
}

void arraytype::rowSwap(uint32 row1, uint32 row2)
{
	FLOAT temp_value;
	for (uint32 index = 0; index < this->col_number; index++)
	{
		temp_value = this->getElement(row1,index);
		this->setElement(row1,index,this->getElement(row2,index));
		this->setElement(row2,index,temp_value);
	}
}

FLOAT	 arraytype::norm( uint32 type  )
{
	FLOAT total = 0.;
	switch(type)
	{
	case 1:
		for (uint32 row = 0; row < row_number; row++ )
		{
			FLOAT temp_total = 0;
			for (uint32 col = 0; col < col_number; col ++)
			{
				temp_total += Abs( this->getElement(row, col) );
			}
			if (total < temp_total) total = temp_total;
		}
		break;
	case 2:
		/*****************************************************************************
		 *  waiting for add function
		 *****************************************************************************/
		break;
	case 0:
		for (uint32 col = 0; col < col_number; col++)
		{
			FLOAT temp_total;
			for (uint32 row = 0; row < row_number; row++ )
			{
				temp_total += Abs( this->getElement(row,col) );
			}
			if (total < temp_total ) total = temp_total;
		}
		break;
	};
	return total;
}


void 	arraytype::rowCopy(arraytype &aim, arraytype target,
							uint32 aim_index, uint32 target_index )
{
	if (aim.col_number != target.col_number )
	{
		println("Error: matrix not equal, please check the data again!!!");
		return;
	}
	for (uint32 col = 0; col < aim.col_number; col++)
	{
		aim.setElement(aim_index, col, target.getElement(target_index,col) );
	}
}


void 	arraytype::colCopy  (arraytype &aim, arraytype target,
								uint32 aim_index, uint32 target_index )
{
	if (aim.row_number != target.row_number )
	{
		println("Error: matrix not equal, please check the data again!!!");
		return;
	}
	//println(aim_index);
	//println(target_index);
	for (uint32 row = 0; row < aim.row_number; row++)
	{
		aim.setElement(row,aim_index, target.getElement(row,target_index) );
	}
}




FLOAT arraytype::detValue()
{
	arraytype temp_arraytype = this->upTrag();
	FLOAT total = 1;
	for (uint32 index = 0; index < row_number; index++)
	{
		total *= this->getElement(index, index);
	}
	return total;
}


arraytype arraytype::inverse()
{
	if (this->row_number != this->col_number)
	{
		println("Error: please check the data!!!");
		return *this;
	}
	arraytype temp_arraytype = *this;
	arraytype out_arraytype(this->row_number);

	for (uint32 index = 0; index < row_number-1; index++)
	{
		FLOAT l_value;
		for (uint32 row = index+1; row<row_number; row++)
		{
			l_value = -1.*temp_arraytype.getElement(row,index)/\
					  	  	  temp_arraytype.getElement(index,index);
			//println(l_value);
			//temp_arraytype.show();
			for (uint32 col = 0; col < col_number; col++)
			{
				temp_arraytype.setElement(row,col,
					l_value*temp_arraytype.getElement(index,col)+\
							temp_arraytype.getElement(row,col));
				out_arraytype.setElement(row,col,
					l_value*out_arraytype.getElement(index,col)+\
							out_arraytype.getElement(row,col) );
			}
//			println("temp array:");
//			temp_arraytype.show();
//			out_arraytype.show();
		}
	}

	//println("temp array:");
	//temp_arraytype.show();
	//out_arraytype.show();
	for(int64 index = row_number-1; index >=0; index--)
	{
		FLOAT l_value;
		for (int64 row = index-1; row >=0; row--)
		{
			l_value = temp_arraytype.getElement(row,index)/\
				  	  	 temp_arraytype.getElement(index,index);
//			println(l_value);
			for(int64 col = row_number-1; col >=0; col --)
			{
				temp_arraytype.setElement(row,col,
					-l_value*temp_arraytype.getElement(index,col)+\
							temp_arraytype.getElement(row,col));
					out_arraytype.setElement(row,col,
						-l_value*out_arraytype.getElement(index,col)+\
							out_arraytype.getElement(row,col) );
				//println(col);
			}
//			println("temp array:");
//			temp_arraytype.show();
//			out_arraytype.show();
		}
	}
	//out_arraytype.show();

	FLOAT factor;
	for(uint32 index = 0; index < row_number; index++)
	{
		factor = 1./temp_arraytype.getElement(index,index);
		for (uint32 col = 0; col < col_number; col++)
		{
			out_arraytype.setElement(index, col,\
					factor * out_arraytype.getElement(index,col));
		}
	}
	return out_arraytype;
}

arraytype   arraytype::luFactor()
{
	arraytype out_arraytype(this->row_number);
	for (uint32 row = 0; row<row_number; row++)
	{
		for(uint32 col = 0; col < col_number; col++)
		{
			FLOAT total = 0;
			if ( col >= row )
			{
				for (uint32 index = 0;index < row; index++)
				{
					//print("d");
					//println(out_arraytype.getElement(row,index));
					//print("d");
					//println(out_arraytype.getElement(index,col));
					total += out_arraytype.getElement(index,col)*\
							out_arraytype.getElement(row,index);
				}
				//println(total);
				out_arraytype.setElement(row,col,\
						this->getElement(row,col)-total);
				continue;
			}

			else
			{
				for (uint32 index = 0; index < row;index++)
				{
					total += out_arraytype.getElement(row,index)*\
							out_arraytype.getElement(index,col);
				}
				//print("l:");
				//println(total);
				out_arraytype.setElement(row,col,\
						(this->getElement(row,col)-total) /\
						out_arraytype.getElement(col,col) );
				continue;
			}
		}
	}
	return out_arraytype;
}

FLOAT arraytype::sumValue()
{
	FLOAT total = 0;
	for(uint32 index = 0; index < row_number*col_number; index++)
	{
		total += item[index];
	}
	return total;
}


void arraytype::show()
{
	for (uint32 row = 0; row < row_number; row++)
	{
		for(uint32 col = 0; col < col_number; col++)
		{
			printf("%16.6f",this->getElement(row,col));
			print(" ");
		}
		println("");
	}
	println("");
}


arraytype::~arraytype() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
