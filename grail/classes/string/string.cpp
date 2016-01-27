//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1995

/***************************************************************************

  File:  classes/string/string.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      string<Item>& string<Item>::assign(const Item* str, const int size)

    This function is a public member of the template class string 
    (declared in string.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/02         Added header and comments


 ***************************************************************************/




/***************************************************************************

      string<Item>& string<Item>::assign(const Item* str, const int size)

  Description:
    This function is a public member of the template class string
    (declared in string.h).  This function converts an array containing
    size Items to a string. The function copies size items from the array 
    to the string without changing the order of the items.  If this string 
    can't currently hold size characters, it is resized to size.  The function
    returns a reference to this string.

    This function can be called in the following ways:
      this_string.assign(item_array, size);

  Parameters:
    const Item* str - the array of items to be copied into the string
    const int size - the size of the array

  Return Value:
    string<Item>& - a reference to this string

 ***************************************************************************/

template <class Item>
string<Item>&
string<Item>::assign(const Item* str, const int size)
{
	// if the maximum size is too small, extend it to size
	if (max < size)
	{
		delete [] p;
		p = new Item[max = size];
	}

	// copy size characters into the string
	for (int i=0; i<size; ++i)
		p[i] = str[i];

	sz = size;
	return *this;
}


