// This is the replace_or_register function used by Daciuk's incremental
// algorithm and others

// First, the algorithm finds the last child of the state prev (i).
// It recursively calls itself if i has any children.  When it is done 
// recursing, it tests to see if i is equivalent to any state in
// the register.  If it is, i is merged to that state.  Otherwise, i is added
// to the register.

template <class Label>
void
fm<Label>::replace_or_register(int prev)
{
	int i;
	i = (*all_states[prev])[(*all_states[prev]).size()-1].get_sink().value();
	// If the state has children, replace or register the most recently
	// added child
	if ((*all_states[i]).size() > 0)
		replace_or_register(i);

	int j, k;

	// Test for equivalence with all states in the register
	for (j = 0; j < all_states.size(); j++)
	{
		if (reg[j] && ((*all_states[j]) == (*all_states[i])))
		{
			// Only one state (prev) has any transitions to i
			k = (*all_states[prev]).size()-1;
			(*all_states[prev])[k].assign(prev,	(*all_states[prev])[k].get_label(), j);
			delete all_states[i];
			all_states.remove(i);
			reg.remove(i);
			return;
		}
			
	}

	reg[i] = true;

}
