//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	November 1993

// *************************************************
// MH 98/09/09  This code does not appear to be used
// *************************************************

template <class Label>
int
fm<Label>::number_of_labels() const
{
	set<Label> 	r;

	return labels(r).size();
}
