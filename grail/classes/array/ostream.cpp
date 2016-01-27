//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	May 1995

/***************************************************************************

  File:  classes/array/ostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following template function:
       template <class Item> 
       ostream& operator<<(ostream& os, const array<Item>& s)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/27         Added header and comments
                                    - fixed problem with printing extra ","
                                      at the end of output


 ***************************************************************************/


#include <iostream.h>


/***************************************************************************

  template <class Item> ostream& operator<<(ostream& os, const array<Item>& s)

  Description:
    This function prints the contents of the array s onto the specified
    output stream in the following format:
      [Item1,Item2, ... ,ItemN]

    The output stream must be valid and open before calling operator<<.

    operator<< must be defined for the class specified as Item.

    This function can be called in the following ways:
      operator<<(output_stream, array_to_print);
      output_stream << array_to_print;

  Parameters:
    ostream& os - the output stream
    const array<Item>& s - the array whose elements will be printed.

  Return Value:
    ostream& - a reference to the output stream
  
 ***************************************************************************/

template <class Item>
ostream&
operator<<(ostream& os, const array<Item>& s)
{
	os << "[";
	if (s.size()>1)
	  {
	  	for (int i=0; i<s.size()-1; ++i)
	             os << s[i] << ",";
		os<<s[i];
		os << "]";
	  }
	else
	  {
		for (int j=0; j<s.size(); j++)
		     os<<s[j];
		os<<"]";
	  }
	return os;
}

