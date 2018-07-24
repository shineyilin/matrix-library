/*
 * point2d.cpp
 *
 *  Created on: 2018Äê7ÔÂ16ÈÕ
 *      Author: admin
 */

#include "point2d.h"

namespace std {

point2d::point2d(POINT2D point2d)
{
	this->item = point2d;
}

point2d::point2d() {
	// TODO Auto-generated constructor stub
	this->item.x = 0;
	this->item.y = 0;
}

point2d point2d::translate(FLOAT x_distance, FLOAT y_distance)
{
	point2d out_point;
	out_point.item.x = this->item.x + x_distance;
	out_point.item.y = this->item.y + y_distance;
	return out_point;
}
point2d point2d::rotate(FLOAT theta)
{
	point2d 	out_point;
	arraytype 	temp(2,1);
	arraytype 	rotate_matrix(2,2);
	temp.setElement(0,0,this->item.x);
	temp.setElement(1,0,this->item.y);
	FLOAT cos_value = cos(theta);
	FLOAT sin_value = sin(theta);

	rotate_matrix.setElement(0,0, cos_value );
	rotate_matrix.setElement(0,1,-sin_value );
	rotate_matrix.setElement(1,0, sin_value );
	rotate_matrix.setElement(1,1, cos_value );
	//temp.show();
	//rotate_matrix.show();
	temp = rotate_matrix*temp;
	out_point.item.x = temp.getElement(0,0);
	out_point.item.y = temp.getElement(1,0);
	return out_point;

}
point2d point2d::rotate(POINT2D center_point, FLOAT theta)
{
	point2d 	out_point;
	arraytype 	temp(2,1);
	arraytype 	rotate_matrix(2,2);
	temp.setElement(0,0,this->item.x-center_point.x);
	temp.setElement(1,0,this->item.y-center_point.y);
	FLOAT cos_value = cos(theta);
	FLOAT sin_value = sin(theta);

	rotate_matrix.setElement(0,0, cos_value );
	rotate_matrix.setElement(0,1,-sin_value );
	rotate_matrix.setElement(1,0, sin_value );
	rotate_matrix.setElement(1,1, cos_value );

	temp = rotate_matrix*temp;

	out_point.item.x = temp.getElement(0,0)+center_point.x;
	out_point.item.y = temp.getElement(0,1)+center_point.y;
	return out_point;
}


point2d point2d::operator +(const point2d &m)
{
	point2d out_point;
	out_point.item.x = m.item.x + this->item.x;
	out_point.item.y = m.item.y + this->item.y;
	return out_point;
}

point2d point2d::operator -(const point2d &m)
{
	point2d out_point;
	out_point.item.x = this->item.x- m.item.x ;
	out_point.item.y = this->item.y -m.item.y;
	return out_point;
}

//point2d point2d::operator = (const point2d& m)
//{
//	this->item = m.item;
//	return *this;
//}

void point2d::show()
{
	printf("x=%f y=%f\n", this->item.x, this->item.y);
}

point2d::~point2d() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
