//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	June 1995

/***************************************************************************

  File:  classes/array/compare.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      array<Item>& array<Item>::operator=(const Item& i)

    This function is a public member of the template class array 
    (declared in array.h).

  Revision History:
  -----------------
    D.Raymond                       Initial version of source code
    M.Hoeberechts  98/02/04         Added header and comments


 ***************************************************************************/




/***************************************************************************

           int array<Item>::compare(const Item* s1, const Item* s2)

  Description:
    This function is a public member of the template class array 
    (declared in array.h).  The purpose of this function is to compare
    the first parameter element with the second parameter element.  The
    comparison is done using < and == as defined for the Item class.
    The function returns -1 if the first item is less than the second
    item, 0 if they are equal, and 1 otherwise.

    The function can be called in the following way:
      result = array<Item>::compare(Item1, Item2);

  Parameters:
    const Item* s1 - a pointer to the first item
    const Item* s2 - a pointer to the second item

  Return Value:
    int - -1 if the first item is less than the second item, 0 if they are
          equal, and 1 otherwise.
  
 ***************************************************************************/

template <class Item>
int
array<Item>::compare(const Item* s1, const Item* s2)
{
	if (*s1 < *s2)
		return -1;
	if (*s1 == *s2)
		return 0;
	return 1;
}






