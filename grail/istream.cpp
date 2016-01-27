//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	May 1995

/***************************************************************************

  File:  classes/array/istream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following template function:
      template <class Item> istream& operator>>(istream& is, array<Item>& s)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/25         Added header and comments

 ***************************************************************************/


#include <iostream.h>
#include "array.h"


/***************************************************************************

   template <class Item> istream& operator>>(istream& is, array<Item>& s)

  Description:
    This function attempts to read elements of type Item from the input
    stream is and insert them into the array s.  If the array already
    contains some elements, the new elements are added to the existing
    ones.  The data on the input stream must be in the following form:
      ...  [Item1,Item2, ... ,ItemN] ...

    Data preceeding the opening bracket and following the closing bracket
    is ignored.  The input stream must be valid and open before calling
    operator>>.  No validation is done on the data inside the brackets -
    it must be of the form specified above.

    operator>> must be defined for the class specified as Item.

    This function can be called in the following ways:
      result = operator>>(input_stream, new_array);
      input_stream >> new_array;

  Parameters:
    istream& is - the input stream from which the data is read
    array<Item>& s - the array to insert the new items into

  Return Value:
    istream& - returns a reference to the input stream
  
 ***************************************************************************/


template <class Item>
istream&
operator>>(istream& is, array<Item>& s)
{
	char	token;
	Item	element;

	// get the opening bracket
	do
		is >> token;
	while (token != '[');

	// get the members of the array
	for (;;)
	{
		is >> element;
		s += element; 

		// get the separator
		is >> token;
		if (token == ']')
			break;
		if (token == ',')
			continue;
	}

	return is;
}



