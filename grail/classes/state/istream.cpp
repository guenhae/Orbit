//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	July 1995


/***************************************************************************

  File:  classes/state/istream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      istream& operator>>(istream& is, state& s)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/04         Added header and comments


 ***************************************************************************/




/***************************************************************************

              istream& operator>>(istream& is, state& s)

  Description:
    This function allows normal states to be inputted from a stream.  An 
    integer is read from the stream and then assigned to be the state number
    for s.  Note that this function does not handle inputting start states,
    final states or null states (the programmer should check that it is not
    called in these cases).  The function returns a reference to the
    input stream.

    This function can be called in the following ways:
      operator>>(input_stream, new_state);
      input_stream >> new_state;

  Parameters:
    istream& is - the input stream
    state& s - stores the inputted state.

  Return Value:
    istream& - a reference to the input stream.

 ***************************************************************************/

istream&
operator>>(istream& is, state& s)
{
	int	i;

	is >> i;
	is.putback(' ');
	s = i;
	return is;
}
