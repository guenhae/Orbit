//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1995

/***************************************************************************

  File:  classes/fl/append.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      fl<Item>& fl<Item>::append(const string<Item>& s)

    This function is a public member of the template class fl (declared 
    in classes/fl/fl.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/05         Added header and comments (adapted from
                                    Release Notes for Grail Version 2.5 by
                                    Darrell Raymond and Roger Robson)

 ***************************************************************************/




/***************************************************************************

              fl<Item>& fl<Item>::append(const string<Item>& s)

  Description:
    This function is a public member of the template class fl (declared 
    in classes/fl/fl.h).  This function appends the parameter string to
    every word in the language.  This is the equivalent of the
    fl <- fl * s operation.  The function returns a reference to this fl.

    This function can be called in the following way:
      this_fl.append(new_string);

  Parameters:
    const string<Item>& s - the string to append to each word in this fl.

  Return Value:
    fl<Item>& - a reference to this fl.

 ***************************************************************************/

template <class Item>
fl<Item>&
fl<Item>::append(const string<Item>& s)
{
	for (int i=0; i<words.size(); ++i)
		words[i] += s;

	return *this;
}

