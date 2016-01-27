//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	August 1994


/***************************************************************************

  File:  classes/array/eq.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      int array<Item>::operator==(const array<Item>& s) const

    This function is a public member of the template class array 
    (declared in array.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/25         Added header and comments


 ***************************************************************************/




/***************************************************************************

          int array<Item>::operator==(const array<Item>& s) const

  Description:
    This function is a public member of the template class array 
    (declared in array.h).  This function checks whether this array
    is equal to the parameter array.  The arrays are judged to be
    equal if they have the same number of elements in the same order.
    The function returns 1 if the arrays are equal and 0 otherwise.

    This function can be called in the following ways:
      this_array.operator==(other_array);
      result = (this_array == other_array);

  Parameters:
    const array<Item>& s - the array to be compared to this array

  Return Value:
    int - returns 1 if the arrays are equal and 0 otherwise
  
 ***************************************************************************/

template <class Item>
int
array<Item>::operator==(const array<Item>& s) const
{
	// first check sizes
	if (s.sz != sz)
		return 0;

	// now test equivalence of each element
	for (int i=0; i<sz; ++i)
		if (s.p[i] != p[i])
			return 0;
	return 1;
}








