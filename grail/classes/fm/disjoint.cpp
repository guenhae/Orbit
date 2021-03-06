//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	August 1994


/***************************************************************************

  File:  classes/fm/disjoint.cpp
  -----

  Description:
  ------------
    This file contains the definitions of the following functions:
      fm<Label>& fm<Label>::disjoint_union(const fm<Label>& t)
      fm<Label>& fm<Label>::disjoint_union(const inst<Label>& a)

    These functions are public members of the template class fm (declared 
    in classes/fm/fm.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/09/06         Added header and comments

 ***************************************************************************/




/***************************************************************************

          fm<Label>& fm<Label>::disjoint_union(const fm<Label>& t)

  Description:
    This function is a public member of the template class fm (declared 
    in classes/re/fm.h).  This function computes the union of this fm and 
    another fm which have which have a distinct set of instructions, start
    states and final states, and stores the result in this fm.  Note that 
    no checking is done to make sure that the sets are actually distinct, 
    and it is thus the programmer's responsibility to ensure that this 
    function is only called with suitable machines.  The resulting fm will 
    contain all the instructions of this fm and the parameter fm and the 
    language represented will contain the union of the set of words in this
    fm and the parameter fm.  The function returns a reference to this fm.

    This function can be called in the following way:
      this_fm.disjoint_union(other_fm);

  Parameters:
    const fm<Label>& t - the fm which should be added to this fm

  Return Value:
    fm<Label>& - a reference to this fm

  
 ***************************************************************************/

template <class Label>
fm<Label>&	
fm<Label>::disjoint_union(const fm<Label>& t)
{
	arcs.disjoint_union(t.arcs);
	start_states.disjoint_union(t.start_states);
	final_states.disjoint_union(t.final_states);

	return *this;
}



/***************************************************************************

        fm<Label>& fm<Label>::disjoint_union(const inst<Label>& a)

  Description:
    This function is a public inline member of the template class fm 
    (declared in classes/re/fm.h).  This function adds the parameter 
    instruction to the set of instructions in this fm.  The parameter 
    instruction must not already exist in the set since no checking is done.
    The function returns a reference to this fm.

    This function can be called in the following way:
      this_fm.disjoint_union(new_inst);

  Parameters:
    const inst<Label>& a - the instruction to be added to this fm.

  Return Value:
    fm<Label>& - a reference to this fm

  
 ***************************************************************************/

template <class Label>
fm<Label>&	
fm<Label>::disjoint_union(const inst<Label>& a)
{
	arcs.disjoint_union(a);
	return *this;
}
