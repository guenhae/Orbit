//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	May 1993


/***************************************************************************

  File:  classes/fm/catenate.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      fm<Label>& fm<Label>::operator^=(const fm<Label>& a)

    This function is a public member of the template class fm (declared 
    in classes/fm/fm.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/09/06         Added header and comments


 ***************************************************************************/




/***************************************************************************

           fm<Label>& fm<Label>::operator^=(const fm<Label>& a)

  Description:
    This function is a public member of the template class fm (declared 
    in classes/re/fm.h).  This function catenates this fm with the 
    parameter fm.  New instructions are added from final states in this 
    fm to the start states of the parameter machine.  The states in the
    parameter machine are renumbered and added to this fm.  The resulting
    language will contain the all the words in the language represented 
    by this fm catenated with the words in the language represented by 
    the parameter fm.  The function returns a reference to this fm.
    
    This function can be called in the following ways:
      this_fm.operator=^(other_fm);
      this_fm =^ other_fm;

  Parameters:
    const fm<Label>& a - the fm to be catenated to this fm

  Return Value:
    fm<Label>& - a reference to this fm

  
 ***************************************************************************/

template <class Label>
fm<Label>&
fm<Label>::operator^=(const fm<Label>& a)
{
	fm<Label>	c;
	fm<Label>	d;
	set<state>	sinks;
	set<Label>	labels;

	// find the maximum state value of invoking machine
	int max = max_state().value() + 1;

	// renumber states of argument machine
	fm<Label> b = a;
	b.renumber(max);

	// make instructions from all final states of the invoking
	// machine to targets of start states of the argument
	// machine

	for (int i=0; i<b.start_states.size(); ++i)
	{
		b.select(b.start_states[i], SOURCE, c);
		for (int j=0; j<c.size(); ++j)
		{
			labels = c[j].get_label();
			sinks = c[j].get_sink();

			// don't forget self loops on start states
			if (c[j].get_sink() == b.start_states[i])
				disjoint_union(c[j]);

			d.cartesian(final_states, labels, sinks);
			arcs += d.arcs;
		}
		//b -= c;  modified by SH 06/18/2007
	}

	arcs.disjoint_union(b.arcs);

	// if language of argument machine contains empty string,
	// keep final states of invoking machine
	sinks.intersect(a.start_states, a.final_states);
	if (sinks.size() > 0)
		final_states.disjoint_union(b.final_states);
	else
		final_states = b.final_states;
		
	return *this;
}
