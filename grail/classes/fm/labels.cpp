//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1993

/***************************************************************************

  File:  classes/fm/labels.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      set<Label>& fm<Label>::labels(set<Label>& r) const

    This function is a public member of the template class fm (declared 
    in classes/fm/fm.h).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/09/07         Added header and comments

 ***************************************************************************/




/***************************************************************************

           set<Label>& fm<Label>::labels(set<Label>& r) const

  Description:
    This function is a public member of the template class fm (declared 
    in classes/re/fm.h).  Collects the set of labels (i.e. the input
    alphabet) used in this fm and stores them in the parameter set.
    Returns a reference to the set of labels.

    This function can be called in the following way:
      this_fm.labels(label_set);

  Parameters:
    set<Label>& r - the set to hold the collected labels

  Return Value:
    set<Label>& - a reference to the set of labels
  
 ***************************************************************************/

template <class Label>
set<Label>&
fm<Label>::labels(set<Label>& r) const
{
	r.clear();
	for (int i=0; i<size(); ++i)
		r += arcs[i].get_label();

	return r;
}
