//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1993

/***************************************************************************

  File:  classes/fm/subset.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      fm<Label>& fm<Label>::subset()

    This function is a public member of the template class fm (declared 
    in classes/fm/fm.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/09/09         Added header and comments

 ***************************************************************************/




/***************************************************************************

                    fm<Label>& fm<Label>::subset()

  Description:
    This function is a public member of the template class fm (declared 
    in classes/re/fm.h).  This function converts this fm to a deterministic
    fm using the method of subset construction.  The resulting fm will not
    necessarily be complete.  The function returns a reference to this fm.

    This function can be called in the following way:
      this_fm.subset();

  Parameters:  none

  Return Value:
    fm<Label>& - a reference to this fm
  
 ***************************************************************************/

template <class Label>
fm<Label>&
fm<Label>::subset()
{
	fm<Label>		m;
	int			i;
	int			j;
	int			k;
	int			no_states;
	state			s1;
	state			s2;
	set<state>		target;
	set<state>		temp2;
	set<Label>		alphabet;
	inst<Label>		t;
	fm<Label>		temp;

	// if already deterministic, do nothing
	if (is_deterministic())
		return *this;

	// sort if necessary
	arcs.sort();

	// remove unreachable states
	reachable_fm();
	reverse();
	reachable_fm();
	reverse();

	// collect the alphabet
	labels(alphabet);

	// add start subset to the list
	list<set<state> >	sub;

	sub += start_states;

	s1 = 0;	
	m.start_states += s1;

	// if some start state is also a final state, add 
	// the new start state to the list of final states
	temp2.intersect(final_states, start_states);
	if (temp2.size() > 0)
		m.final_states += s1;

	// for each existing set in the subset list, 
	// find a new reachable subset
	no_states = 1;

	for (i=0; i<no_states; ++i)
	{
		for (j=0; j<alphabet.size(); ++j)
		{
			target.clear();
			for (k=0; k<sub[i].size(); ++k)
			{
				select(alphabet[j], sub[i][k], SOURCE, temp);
				target += temp.sinks(temp2);
			}

			if (target.size() == 0)
				continue;

			// create states for an instruction
			s1 = i;

			if ((k = sub.member(target)) < 0)
			{
				sub += target;
				s2 = no_states++;
				temp2.intersect(final_states, target);
				if (temp2.size() > 0)
					m.final_states += s2;
			}
			else
				s2 = k;

			t.assign(s1, alphabet[j], s2);
			m.arcs += t;
		}
	}

	*this = m;
	return *this;
}
