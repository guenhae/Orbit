//	This code copyright (c) by the Grail project
//	No commercial use permitted without written consent.
//	June 1995

/***************************************************************************

  File:  classes/bits/gt.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      int bits::operator>(const bits& f) const 

    This function is a public member of the class bits (declared in bits.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/29         Added header and comments


 ***************************************************************************/




/***************************************************************************

                int bits::operator>(const bits& f) const 

  Description:
    This function is a public member of the class bits (declared in bits.h). 
    This is the greater than operator for bitmaps.   A bitmap is judged to 
    be greater than another bitmap if it contains more bits or the binary
    value of one of its blocks is greater than the corresponding binary 
    value in the other bitmap (this criteria is somewhat arbitrary).  
    The function returns 1 if this bitmap is greater than the parameter 
    bitmap and 0 otherwise.

    This function can be called in the following ways:
      value = this_bits.operator>(test_bits);
      value = (this_bits > new_bits);

  Parameters:
    const bits& f - the bitmap to be compared to this bitmap

  Return Value:
    int - returns 1 if this bitmap is greater than the parameter bitmap and
          0 otherwise.
    
 ***************************************************************************/

int 
bits::operator>(const bits& f) const 
{
	if (*this < f || *this == f)
		return 0;

	return 1;
}

