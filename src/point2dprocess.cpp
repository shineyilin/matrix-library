/*
 * point2d.cpp
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: admin
 */

#include "point2dprocess.h"

namespace std {

point2dprocess::point2dprocess()
{
	// TODO Auto-generated constructor stub

}

point2dprocess::point2dprocess(POINT2D point2d)
{
	// TODO Auto-generated constructor stub
	try{
		this->point2d_list.push_back(point2d);
		if (this->point2d_list.size()!= point2d_list.size() )
			throw "error: can not get the input data!!!";
	}
	catch(char &str )
	{
		println(str);
		return;
	}
}

point2dprocess::point2dprocess(POINT2D_LIST point2d_list)
{
	try{
		this->point2d_list = point2d_list;
		if (this->point2d_list.size()!= point2d_list.size() )
			throw "error: can not get the input data!!!";
	}
	catch(char &str )
	{
		println(str);
		return;
	}
}

void point2dprocess::showPoint2DData()
{
	uint32 length;
	length = this->point2d_list.size();
	println("====point 2d data list:====");
	for (uint32 index = 0; index < length; index ++)
	{
		print(this->point2d_list[index].x);
		print(" ");
		print(this->point2d_list[index].y);
		println("");
	}
	println("====point 2d data end :====");
}

bool point2dprocess::initPoint2DData(POINT2D_LIST point2d_list)
{
	try{
		this->point2d_list = point2d_list;
		if (this->point2d_list.size()!= point2d_list.size() )
			throw "error: can not get the input data!!!";
	}
	catch(char &str )
	{
		println(str);
		return false;
	}
	return true;
}

bool point2dprocess::clearPoint2DData()
{
	this->point2d_list.clear();
	//return true;
	if (this->point2d_list.size() == 0)
	{
		println( "clear point data sucess!!!" );
		return true;
	}
	else
	{
		println( "can not clear point list data, please try again!!!");
		return false;
	}
}

FLOAT point2dprocess::getInsert2DData(FLOAT x_value)
{
	FLOAT y_value;
	static uint32 bef_index = 1;
	uint32 length 			= point2d_list.size();
	if (x_value < this->point2d_list[0].x)
	{
		printf("error:index out of range, x data less then list\n");
		return this->point2d_list[0].y;
	}
	else if (x_value > this->point2d_list[length-1].x)
	{
		printf("error:index out of range, x data large then list\n");
		return this->point2d_list[length-1].y;
	}
	int real_index;
	for (uint32 index = 0; index < length; index++ )
	{
		real_index = (index+bef_index)%length;
		if ( x_value <= this->point2d_list[real_index].x )
		{
			FLOAT x0;
			FLOAT x1;
			FLOAT y0;
			FLOAT y1;
			FLOAT k;
			x0 = this->point2d_list[real_index-1].x;
			x1 = this->point2d_list[real_index  ].x;

			y0 = this->point2d_list[real_index-1].y;
			y1 = this->point2d_list[real_index  ].y;

			//if ()
			k = (y1-y0)/(x1-x0);
			y_value = y0 + k*(x_value-x0);
			return y_value;
		}
	}
	return -1;
}

FLOAT point2dprocess::getInsert2DDataEx(FLOAT x_value)
{
	FLOAT y_value;
	static uint32 bef_index = 1;
	uint32 length 			= point2d_list.size();
	if (x_value < this->point2d_list[0].x)
	{
		printf("error:index out of range, x data less then list\n");
		return this->point2d_list[0].y;
	}
	else if (x_value > this->point2d_list[length-1].x)
	{
		printf("error:index out of range, x data large then list\n");
		return this->point2d_list[length-1].y;
	}
	int real_index;
	for (uint32 index = 0; index < length; index++ )
	{
		real_index = (index+bef_index)%length;
		if ( x_value <= this->point2d_list[real_index].x )
		{
			FLOAT x0;
			FLOAT x1;
			FLOAT y0;
			FLOAT y1;
			FLOAT k;
			x0 = this->point2d_list[real_index-1].x;
			x1 = this->point2d_list[real_index  ].x;

			y0 = this->point2d_list[real_index-1].y;
			y1 = this->point2d_list[real_index  ].y;

			if (y0*y1 <= 0)
			{
				if (y0 <= 0)
				{
					if (x_value <= (x0+x1)/2 )
					{
						x1 	= (x0+x1)/2;
						y1 	= -inf;
						k 	= (y1-y0)/(x1-x0);
						y_value = y0 + k*(x_value-x0);
						return y_value;
					}
					else if (x_value > (x0+x1)/2 )
					{
						x0 	= (x0+x1)/2;
						y0 	= inf;
						k 	= (y1-y0)/(x1-x0);
						y_value = y0 + k*(x_value-x0);
						return y_value;
					}
				}
				else if (y0 >0)
				{
					if (x_value <= (x0+x1)/2 )
					{
						x1 = (x0+x1)/2;
						y1 = inf;
						k 	= (y1-y0)/(x1-x0);
						y_value = y0 + k*(x_value-x0);
						return y_value;
					}
					else if (x_value > (x0+x1)/2 )
					{
						x0 = (x0+x1)/2;
						y0 = -inf;
						k 	= (y1-y0)/(x1-x0);
						y_value = y0 + k*(x_value-x0);
						return y_value;
					}
				}
			}

			else
			{
				k = (y1-y0)/(x1-x0);
				y_value = y0 + k*(x_value-x0);
				return y_value;
			}

		}
	}
	return -1;

}
void 	point2dprocess::translatePoint2D(FLOAT x_distance, FLOAT y_distance)
{
	for (uint32 index = 0; index < this->point2d_list.size(); index++)
		this->point2d_list[index] =  \
				              this->translate(point2d_list[index],x_distance,y_distance);
}
void 	point2dprocess::rotatePoint2D   (FLOAT theta)
{
	for (uint32 index = 0; index < this->point2d_list.size(); index++)
		this->point2d_list[index]=this->rotate(point2d_list[index],theta);
}
void    point2dprocess::rotatePoint2D   (POINT2D center_point, FLOAT theta)
{
	for (uint32 index = 0; index < this->point2d_list.size(); index++)
		this->point2d_list[index] = this->rotate(point2d_list[index],center_point, theta);
}
POINT2D point2dprocess::translate		(POINT2D point,FLOAT x_distance, FLOAT y_distance)
{
	POINT2D out_point;
	out_point.x = point.x - x_distance;
	out_point.y = point.y - y_distance;
	return out_point;
}
POINT2D point2dprocess::rotate			(POINT2D point,FLOAT theta)
{
	POINT2D 	out_point;
	arraytype 	temp(1,2);
	arraytype 	rotate_matrix(2,2);
	temp.setElement(0,0,point.x);
	temp.setElement(0,1,point.y);
	rotate_matrix.setElement(0,0, cos(theta));
	rotate_matrix.setElement(0,1,-sin(theta));
	rotate_matrix.setElement(1,0, sin(theta));
	rotate_matrix.setElement(1,1, cos(theta));
	temp = temp*rotate_matrix;
	out_point.x = temp.getElement(0,0);
	out_point.y = temp.getElement(0,1);
	return out_point;
}
POINT2D point2dprocess::rotate			(POINT2D point,POINT2D center_point, FLOAT theta)
{
	POINT2D 	out_point;
	arraytype 	temp(1,2);
	arraytype 	rotate_matrix(2,2);
	temp.setElement(0,0,point.x-center_point.x);
	temp.setElement(0,1,point.y-center_point.y);
	rotate_matrix.setElement(0,0, cos(theta));
	rotate_matrix.setElement(0,1,-sin(theta));
	rotate_matrix.setElement(1,0, sin(theta));
	rotate_matrix.setElement(1,1, cos(theta));
	temp = temp*rotate_matrix;
	out_point.x = temp.getElement(0,0)+center_point.x;
	out_point.y = temp.getElement(0,1)+center_point.y;
	return out_point;
}
point2dprocess::~point2dprocess() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
