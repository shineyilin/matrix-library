/*
 * test_point2d.cpp
 *
 *  Created on: 2018Äê7ÔÂ24ÈÕ
 *      Author: admin
 */

#include "test_point2d.h"


void test_Point2D()
{
	println("translate point 2d:");
	test_Point2DTranslate();
	println("rotate point 2d:");
	test_Point2DRotate();
	println("rotate center point 2d:");
	test_Point2DRotateCenter();
	println("operator point 2d:");
	test_Point2DOperator();
}


void test_Point2DTranslate()
{
	POINT2D t;
	t.x = 1;
	t.y = 2;
	point2d p(t);
	point2d r;
	p.show();
	p = p.translate(3,1);
	p.show();
}

void test_Point2DRotate()
{
	POINT2D t;
	t.x = 0;
	t.y = 2;
	point2d p(t);
	point2d r;
	p.show();
	FLOAT theta = 90. * pi / 180.;
	p = p.rotate(theta);
	p.show();
}

void test_Point2DRotateCenter()
{
	POINT2D t;
	t.x = 0;
	t.y = 2;
	point2d p(t);
	point2d r;
	p.show();
	FLOAT theta  = 90. * pi / 180.;
	POINT2D center_point;
	center_point.x = 0;
	center_point.y = 0;
	p = p.rotate(center_point,theta);
	p.show();
}
void test_Point2DOperator()
{

}
