//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1994



/***************************************************************************

  File:  classes/re/ostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      template <class S> ostream& operator<<(ostream& os, const re<S>& r)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/11         Added header and comments

 ***************************************************************************/




/***************************************************************************

    template <class S> ostream& operator<<(ostream& os, const re<S>& r)

  Description:
    This function allows the parameter regular expression to be outputted
    on the parameter stream.  The actual output is done by calling
    print(ostream&,int) on r.  The output stream should be valid and
    open before calling this function.  The function returns a reference to 
    the output stream.

    This function can be called in the following ways:
      operator<<(output_stream, reg_exp);
      output_stream << reg_exp;

  Parameters:
    ostream& os - the output stream
    const re<S>& r - the regular expression to output

  Return Value:
    ostream& - a reference to the output stream
  
 ***************************************************************************/

template <class S>
ostream&
operator<<(ostream& os, const re<S>& r)
{
	r.print(os, 1);
	return os;
}
