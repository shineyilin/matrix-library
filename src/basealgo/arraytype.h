/*
 * arraytype.h
 *
 *  Created on: 2018Äê7ÔÂ5ÈÕ
 *      Author: admin
 */

#ifndef ARRAYTYPE_H_
#define ARRAYTYPE_H_
#include "matrix.h"
#include "fileio.h"

namespace std {

/*
 *
 */



enum array_type
{ ZEROS,ONES, RANDS	};

class arraytype {
public:
	arraytype();
	arraytype(int m, int n);
	arraytype(int n);
	arraytype( array_type type ,int m,int n);
	arraytype(const arraytype &m);
	arraytype(FLOAT *item_input, int m, int n);
	virtual ~arraytype();

public:
	bool		     	fromFile(string file);
	uint32 			 	getRowNumber();
	uint32 			 	getColNumber();

	arraytype        	getRowElement(uint32 index);
	arraytype        	getColElement(uint32 index);

public:
	void 		show();
public:
	arraytype 	trans			(	  );
	FLOAT 		getElement		(int i, int j) const;
	void  		setElement		(int i, int j, FLOAT value);
	arraytype 	operator +		(const arraytype &m);
	arraytype 	operator -		(const arraytype &m);
	arraytype 	operator *		(const arraytype &m);
	arraytype   operator *		(const FLOAT     &value);
	arraytype   operator =		(const arraytype &m);
	arraytype 	upTrag	  		(	  );
	arraytype   inverse	  		(	  );
	FLOAT		detValue  		(	  );
	arraytype   luFactor 	  	(	  );
	FLOAT  		sumValue		(	  );
	FLOAT		norm			( uint32 type  );

public:
	void 		rowSwap(uint32 i, uint32 j,FLOAT factor);
	void 		rowSwap(uint32 i, uint32 j);
	void  		rowCopy(arraytype &aim, arraytype target, uint32 aim_index, uint32 target_index);
	void		colCopy(arraytype &aim, arraytype target, uint32 aim_index , uint32 target_index);

private:
	FLOAT 	*item;
	uint32 	row_number;
	uint32 	col_number;
};

} /* namespace std */

#endif /* ARRAYTYPE_H_ */
