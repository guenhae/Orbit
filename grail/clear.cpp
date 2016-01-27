//	This code copyright (c) by the Grail project
//	No commercial use permitted without written consent.
//	September 1995

/***************************************************************************

  File:  classes/bits/clear.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      void bits::clear()

    This function is a public member of the class bits (declared in bits.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/29         Added header and comments


 ***************************************************************************/




/***************************************************************************

                           void bits::clear()

  Description:
    This function is a public member of the class bits (declared in bits.h).  
    This function sets all the bits in this bitmap to 0. 

    This function can be called in the following ways:
      this_bitmap.clear();

  Parameters:  none

  Return Value:  none
  
 ***************************************************************************/

void
bits::clear()
{
	// bzero((char *) b, (max + 1) * sizeof(unsigned int));
	memset((char *) b, 0, (max + 1) * sizeof(unsigned int));
	sz = max;
}
