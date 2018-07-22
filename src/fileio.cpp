/*
 * fileio.cpp
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: admin
 */

#include "fileio.h"

namespace std {

fileio::fileio() {
	// TODO Auto-generated constructor stub
}
fileio::fileio(string str)
{
	if (str.length() == 0)  return;
	hand = fopen(str.c_str(), "r");
	if (hand != NULL) 	return;
	else				printf("open file error!!");
}

bool fileio::open(string str)
{
	if (str.length() == 0)  return false;
	hand = fopen(str.c_str(), "r");
	if (hand != NULL) 	return true;
	else				printf("open file error!!");
	return true;
}

VALUE_STRING fileio::read()
{
	VALUE_STRING 	data;
	char 			ch;
	ch = fgetc(hand);
	while(ch != EOF)
	{
		data.cmd +=ch;
		ch = fgetc(hand);
	}
	return data;
}

VALUE_STRING fileio::readline()
{
	VALUE_STRING data;
	char ch;
	ch = fgetc(hand);
	while(ch != EOF and ch != '\n')
	{
		data.cmd 	+= 	ch;
		ch 			=	fgetc(hand);
	}
	if( ch == '\n' ) data.type = 'o';
	if( data.cmd.length()!=0 ) data.type ='c';
	if( ch == EOF ) data.type = 'e';
	//ch = fgetc(hand);
	return data;
}

VALUE_STRING_LIST fileio::splitLineData(VALUE_STRING line_str)
{

	char split_flag = ' ';
	VALUE_STRING_LIST value_string_list;
	uint32 length = line_str.cmd.size();

	string temp_value_string;
	string temp_value_list_string = line_str.cmd;
	char   temp_str;
	for (	uint32 index = 0; index < length; length ++	)
	{
		temp_str 			= temp_value_list_string[index];
		if (temp_str == split_flag  )
		{
			if ( temp_value_string.size() !=0 or index +1 == length)
			{
				print(temp_value_string);
				value_string_list.push_back(temp_value_string);
				temp_value_string.clear();
			}
		}
		temp_value_string 	+= 	temp_str;
	}
	return value_string_list;
}

FLOAT fileio::str2Float(string value_string)
{
	FLOAT value;
	value = atof(value_string.c_str());
	return value;
}

/***********************************************************************
 * change string data to 2D point
 **********************************************************************/
POINT2D fileio::str2Point2D(VALUE_STRING line_str)
{
	POINT2D 			point2d;
	VALUE_STRING_LIST 	value_string_list;
	value_string_list 	= this->splitLineData(line_str);
	uint8 length 		= value_string_list.size();
	if (length != 2)
	{
		point2d.flag = 'N';
		return point2d;
	}
	point2d.x 		= this->str2Float(value_string_list[0]);
	point2d.y 		= this->str2Float(value_string_list[1]);
	point2d.flag 	= 'Y';
	return point2d;
}

VECTOR fileio::str2Vector(VALUE_STRING line_str)
{
	VECTOR vector_list;
	VALUE_STRING_LIST value_string_list;
	value_string_list = this->splitLineData(line_str);
	uint8 length 	  = value_string_list.size();
	if (length == 0)
	{
		vector_list.push_back(0);
		return vector_list;
	}
	FLOAT temp_value;
	for (int index = 0; index < length; index++)
	{
		temp_value = this->str2Float(value_string_list[index]);
		vector_list.push_back(temp_value);
	}
	return vector_list;
}


POINT2D_LIST fileio::readSplitDataToPoint2DList()
{
	POINT2D_LIST point_list;
	VALUE_STRING value_line_string;
	POINT2D		 point2d;
	while(true)
	{
		value_line_string = 	this->readline();
		if 		( value_line_string.type == 'e') break;
		else if ( value_line_string.type == 'c')
		{
			point2d = this->str2Point2D	(value_line_string);
			if (point2d.flag == 'Y')
				point_list.push_back	(point2d);
		}
	}
	return point_list;
}



MATRIX fileio::readSplitDataToMatrix()
{
	MATRIX matrix_list;
	VECTOR vector_list;
	VALUE_STRING value_line_string;
	while(true)
	{
		value_line_string = this->readline();
		if ( value_line_string.type == 'e') break;
		else if ( value_line_string.type == 'c')
		{
			vector_list = this->str2Vector(value_line_string);
			matrix_list.push_back(vector_list);
		}
	}
	return matrix_list;
}


bool fileio::close()
{
	fclose(hand);
	return true;
}


fileio::~fileio() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
