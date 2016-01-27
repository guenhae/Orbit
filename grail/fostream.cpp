//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	May 1995

/***************************************************************************

  File:  classes/array/fostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following template function:
      template <class Item> void print(ostream& os, array<Item>& s)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/25         Added header and comments


 ***************************************************************************/


//#include <iostream.h> by SH 05/20/2005


/***************************************************************************

      template <class Item> void print(ostream& os, array<Item>& s)

  Description:
    This function prints the contents of the array s onto the specified
    output stream in the following format:
      [Item1,Item2, ... ,ItemN]

    The output stream must be valid and open before calling print.

    operator<< must be defined for the class specified as Item.

    This function can be called in the following way:
      print(output_stream, array_to_print);

  Parameters:
    ostream& os - the output stream
    array<Item>& s - the array whose elements will be printed.

  Return Value:  none
  
 ***************************************************************************/

template <class Item>
void
print(ostream& os, const array<Item>& s)
{
	int i,j; //by SH 05/20/2005
	os << "[";
	if (s.size()>1)
	  {
	  	for (i=0; i<s.size()-1; ++i)
	             os << s[i] << ",";
		os<<s[i];
		os << "]";
	  }
	else
	  {
		for (j=0; j<s.size(); j++)
		     os<<s[j];
		os<<"]";
	  }
//	return os;
}


