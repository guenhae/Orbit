//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	July 1995


/***************************************************************************

  File:  classes/state/minuseq.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      void state::operator-=(const state& s)
      void state::operator-=(int i)

    This function is a public member of the class state (declared in state.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/04         Added header and comments


 ***************************************************************************/




/***************************************************************************

                     void state::operator-=(const state& s)

  Description:
    This function is a public member of the class state (declared in state.h).
    This function decrements this state's number by the value of the parameter
    state's number.  If the parameter state has a larger number than this
    state, an error message is printed on the standard error stream and no
    change is made.

    This function can be called in the following ways:
      this_state.operator-=(other_state);
      this_state -= other_state;

  Parameters:
    const state& s - the state whose number should be subtracted from this
                     state's number.

  Return Value:  none
  
 ***************************************************************************/

void
state::operator-=(const state& s)
{
	if (s.number > number)
	{
		std::cerr << "error in state: attempted " << value() << " - "  //by SH 05/20/2005
					<< s.value() << "\n";
		return;
	}
	number -= s.number;	
}



/***************************************************************************

                        void state::operator-=(int i)

  Description:
    This function is a public member of the class state (declared in state.h).
    This function decrements this state's number by the parameter value.
    If the parameter value is larger than this state's number, an error
    message is printed on the standard error stream and no change is made.  
    This function should only be called for normal states.

    This function can be called in the following ways:
      this_state.operator-=(minus_value);
      this_state -= minus_value;

  Parameters:
    int i - the value by which this state's number should be decremented

  Return Value:  none

 ***************************************************************************/

void
state::operator-=(int i)
{
	if (i > (number - 2))
	{
		std::cerr << "error in state: attempted " << value() << " - "  //by SH 05/20/2005
					<< i - 2 << "\n";
		return;
	}
	number -= i;
}








