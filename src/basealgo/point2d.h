/*
 * point2d.h
 *
 *  Created on: 2018Äê7ÔÂ16ÈÕ
 *      Author: admin
 */

#ifndef POINT2D_H_
#define POINT2D_H_
#include "point2dprocess.h"
#include "typedef.h"
#include "arraytype.h"

namespace std {


/*
 *
 */
class point2d {
public:
	point2d(POINT2D point2d);
	point2d();
	point2d(const point2d& m);
	virtual ~point2d();
public:
	point2d translate(FLOAT x_diatance, FLOAT y_diatance);
	point2d rotate(FLOAT theta);
	point2d rotate(POINT2D center_point ,FLOAT theta);

	point2d operator + (const point2d &m);
	point2d operator - (const point2d &m);

	//point2d operator = (const point2d &m);

	void show();

private:
	POINT2D item;
};

} /* namespace std */

#endif /* POINT2D_H_ */
