/*
 * testfitmethod.cpp
 *
 *  Created on: 2018Äê7ÔÂ24ÈÕ
 *      Author: admin
 */

#include "test_fit_method.h"


void test_FitMethod()
{
	test_FitMethodInit();
	test_FitMethodNull();
}

void test_FitMethodNull()
{
	arraytype point_list(3,2);
	point_list.setElement(0,0,1);
	point_list.setElement(0,1,1);

	point_list.setElement(1,0,2);
	point_list.setElement(1,1,2);

	point_list.setElement(2,0,5);
	point_list.setElement(2,1,3);
	arraytype fit_param;
	fitmethod fit_hand(point_list);
	fit_param = fit_hand.startFitMethod();
	fit_param.show();
}
void test_FitMethodInit()
{

}
