//	This code copyright (c) by the Grail project
//	No commercial use permitted without written consent.
//	June 1995

/***************************************************************************

  File:  classes/bits/ostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      ostream& operator<<(ostream& os, const bits& f)

    This function is a friend of the class bits (declared in bits.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/29         Added header and comments


 ***************************************************************************/




/***************************************************************************

               ostream& operator<<(ostream& os, const bits& f)

  Description:
    This function is a friend of the class bits (declared in bits.h).  
    This function outputs the specified bitmap on the output stream
    in the following format:
      0101010101110 ....
    (1's and 0's for bits followed by an end of line).
    The output stream must be valid and open before calling this function.

    This function can be called in the following way:
      output_stream << bitmap;

  Parameters:
    ostream& os - the output stream
    const bits& f - the bitmap to be outputted

  Return Value:
    ostream& - a reference to the output stream
  
 ***************************************************************************/

ostream& 
operator<<(ostream& os, const bits& f)
{
	for (int i=0; i<f.size(); ++i)
		os << f[i];
	return os << std::endl; //by SH 05/20/2005
}
