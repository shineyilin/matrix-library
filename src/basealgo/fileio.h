/*
 * fileio.h
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: admin
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "point2dprocess.h"

namespace std {

typedef struct
{
	int index;
	char type;
	string cmd;
}VALUE_STRING;

typedef vector<string> VALUE_STRING_LIST;




class fileio {

public:
	fileio				(	);
	fileio				(string str);
	virtual ~fileio		(	);
public:
	bool				open			(string str);
	VALUE_STRING 		read			(	);
	VALUE_STRING 		readline		(	);

public:
	POINT2D_LIST 		readSplitDataToPoint2DList	(	);
	MATRIX				readSplitDataToMatrix		(	);
	bool 				close						(	);

public:
	VALUE_STRING_LIST 	splitLineData	(VALUE_STRING line_str	);
	FLOAT				str2Float		(string value_string	);
	POINT2D				str2Point2D		(VALUE_STRING line_str	);

	VECTOR				str2Vector		(VALUE_STRING line_str  );
private:
	FILE *hand = NULL;
	//string data;
};

} /* namespace std */

#endif /* FILEIO_H_ */
