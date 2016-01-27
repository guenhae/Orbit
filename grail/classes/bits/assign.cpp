//	This code copyright (c) by the Grail project
//	No commercial use permitted without written consent.
//	June 1995

/***************************************************************************

  File:  classes/bits/assign.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      void bits::operator=(const bits& f) 

    This function is a public member of the class bits (declared in bits.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/29         Added header and comments


 ***************************************************************************/




/***************************************************************************

                     void bits::operator=(const bits& f) 

  Description:
    This function is a public member of the class bits
    (declared in bits.h).  This is the assignment operator for bitmap.
    It assigns this array to contain the same bit values as the parameter
    bitmap.  If this bitmap is larger than the parameter bitmap its size is
    not reduced (and thus the upper bits are ignored).  If this bitmap is
    not large enough, its size is changed to be the same as the parameter
    bitmap's size.

    This function can be called in the following ways:
      this_bitmap.operator=(new_bitmap);
      this_bitmap = new_bitmap;

  Parameters:
    const bits& f - a reference to the bitmap to copy into this bitmap

  Return Value:  none
  
 ***************************************************************************/

void 
bits::operator=(const bits& f) 
{
	// test for self-assignment
	if (this == &f)
		return;

	// allocate if necessary
	if (max < f.max)
	{
		delete [] b;
		max = f.max; 
		b = new unsigned int[max + 1];
		b[max] = 0;
	}

	// copy the bits
	memcpy(b, f.b, f.max * sizeof(unsigned int));
	sz = f.max;
}

