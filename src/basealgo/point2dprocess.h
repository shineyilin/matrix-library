/*
 * point2d.h
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: admin
 */

#ifndef POINT2DPROCESS_H_
#define POINT2DPROCESS_H_

#include "typedef.h"
#include "matrix.h"
#include "arraytype.h"
namespace std {
/*
 *
 */



class point2dprocess:public mymatrix {
public:
	point2dprocess(POINT2D point2d);
	point2dprocess(POINT2D_LIST point2d_list);
	point2dprocess();

	virtual ~point2dprocess();
public:
	bool	initPoint2DData  ( POINT2D_LIST point2d_list );
	bool 	clearPoint2DData ( );
	FLOAT 	getInsert2DData  ( FLOAT x_value );
	FLOAT	getInsert2DDataEx( FLOAT x_value );
	void 	showPoint2DData  (  );

public:
	void 	translatePoint2D(FLOAT x_distance, FLOAT y_distance);
	void 	rotatePoint2D   (FLOAT theta);
	void    rotatePoint2D   (POINT2D center_point, FLOAT theta);

	POINT2D translate		(POINT2D point, FLOAT x_distance, FLOAT y_distance);
	POINT2D rotate			(POINT2D point, FLOAT theta);
	POINT2D rotate			(POINT2D point, POINT2D center_point, FLOAT theta);

private:
	POINT2D_LIST point2d_list;
};

} /* namespace std */

#endif /* POINT2DPROCESS_H_ */
