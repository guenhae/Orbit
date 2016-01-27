template <class Label>
void
fm<Label>::attach()
{
	// Nothing needs to be done if attach has already been called.
	if (attached)
		return;
		
	int n = number_of_states();
	int i;

	// First create empty states in all_states
	for (i = 0; i < n; i++)
		all_states += new atstate<Label>();

	// Fill the empty states with transitions from arcs and delete
	// the entries in arcs after they are copied.
	for (i = arcs.size()-1; i >= 0; i--)
	{
		(*all_states[arcs[i].get_source().value()]) += arcs[i];
		arcs.remove(i);
	}

	// Copy information from the set final_states
	for (i = final_states.size()-1; i >= 0; i--)
	{
		(*all_states[final_states[i].value()]).set_final(true);
		final_states.remove(i);
	}

	attached = true;
}

template <class Label>
void
fm<Label>::unattach()
{
	// Nothing needs to be done if unattach has already been called.
	if (!attached)
		return;
		
	int i, j;
	inst<Label> temp_arc;

	// This loop adds transitions to arcs state by state and deletes
	// entries in all_states as their contents are copied.
	for (i = all_states.size()-1; i >= 0; i--)
	{
		for (j = 0; j < (*all_states[i]).size(); j++)
		{
			temp_arc = (*all_states[i])[j];
			arcs.disjoint_union(temp_arc);
		}
		if ((*all_states[i]).final())
			final_states += i;
			
		delete all_states[i];
		all_states.remove(i);
	}

	attached = false;
}

template <class Label>
array<atstate<Label> * >
fm<Label>::attach_inv()
{
	attach();
		
	int i, j, current;

	array<atstate<Label> * > temp;

	inst<Label> temp_inst;
	for (i = 0; i < all_states.size(); i++)
		for (j = 0; j < (*all_states[i]).size(); j++)
		{
			// Find the state that this transition belongs to
			current = (*all_states[i])[j].get_sink().value();
			
			// Create new states as needed
			while(current >= temp.size())
				temp += new atstate<Label>();
			
			// Reverse the transition
			temp_inst.assign((*all_states[i])[j].get_sink(),
				(*all_states[i])[j].get_label(),
				(*all_states[i])[j].get_source());
			
			(*temp[current]) += temp_inst;
		}

	return temp;
}
