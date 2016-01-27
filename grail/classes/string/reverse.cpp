//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1996


/***************************************************************************

  File:  classes/string/reverse.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      string<Item>& string<Item>::reverse()

    This function is a public member of the template class string 
    (declared in string.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/03         Added header and comments


 ***************************************************************************/




/***************************************************************************

                string<Item>& string<Item>::reverse()

  Description:
    This function is a public member of the template class string
    (declared in string.h).  The purpose of this function is to reverse
    the order of the characters in this string.  After the execution of
    this function, this string will consist of the same characters,
    but the last will be in the first position, the second last in the
    second position etc.  The function returns a reference to this
    string.

    This function can be called in the following way:
      this_string.reverse();

  Parameters:  none

  Return Value:
    string<Item>& - a reference to this string

  
 ***************************************************************************/

template <class Item>
string<Item>&
string<Item>::reverse()
{
	Item 	tmp;
	int	mid = sz/2;
	
	for (int j=0; j<mid; ++j)
	{
		tmp = p[j];
		p[j] = p[sz-j-1];
		p[sz-j-1] = tmp;
	}

	return *this;
}
