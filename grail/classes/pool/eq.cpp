//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1995

/***************************************************************************

  File:  classes/pool/eq.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      int pool<S>::operator==(const pool<S>& s) const

    This function is a public member of the template class pool 
    (declared in pool.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/28         Added header and comments


 ***************************************************************************/




/***************************************************************************

          int pool<S>::operator==(const pool<S>& s) const

  Description:
    This function is a public member of the template class pool 
    (declared in pool.h).  This function checks whether this pool
    is equal to the parameter pool.  The pools are judged to be
    equal if they have they are managing the identical pool of arrays.
    The function returns 1 if the pools are equal and 0 otherwise.

    This function can be called in the following ways:
      this_pool.operator==(other_pool);
      result = (this_pool == other_pool);

  Parameters:
    const pool<S>& s - the pool to be compared to this pool

  Return Value:
    int - returns 1 if the pools are equal and 0 otherwise
  
 ***************************************************************************/

template <class S>
int
pool<S>::operator==(const pool<S>& s) const
{
	// if (b != s.b)
	//	return 0;

	if (p != s.p)
		return 0;

	return 1;
}
