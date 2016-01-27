//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1995

/***************************************************************************

  File:  classes/pool/lt.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      int pool<S>::operator<(const pool<S>& s) const

    This function is a public member of the template class pool 
    (declared in pool.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/28         Added header and comments


 ***************************************************************************/




/***************************************************************************

         int pool<S>::operator<(const pool<S>& s) const

  Description:
    This function is a public member of the template class pool 
    (declared in pool.h).  This function determines whether this pool
    is less than the parameter pool.  This pool is judged to be less
    than the parameter pool if its bits are less or its array of pointers
    is less (rather arbitrary criteria).  If the pools are identical, 
    0 is returned.  If this pool is less than the parameter pool, 1 is 
    returned.

    This function can be called in the following ways:
      result = this_pool.operator<(test_pool);
      result = (this_pool < test_pool);

  Parameters:
    const pool<S>& s - the pool to be compared to this pool

  Return Value:
    int - returns 1 if this pool is less than the parameter pool, 0
          otherwise.
  
 ***************************************************************************/

template <class S>
int
pool<S>::operator<(const pool<S>& s) const
{
	if (b < s.b)
		return 1;

	if (p < s.p)
		return 1;

	return 0;
}
