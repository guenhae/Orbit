template <class Label>
void
fcm<Label>::attach()
{
	// Nothing needs to be done if attach has already been called.
	if (attached)
		return;
		
	int i, current, sink;

	// Fill the empty states with transitions from arcs and delete
	// the entries in arcs after they are copied.
	for (i = fm<Label>::arcs.size()-1; i >= 0; i--)
	{
		// Find the state that this transition belongs to
		current = fm<Label>::arcs[i].get_source().value();

		// Find the sink
		sink = fm<Label>::arcs[i].get_source().value();

		// Create new states as needed
		while ((current >= all_states.size()) || (sink >= all_states.size()))
			all_states += new atstate<Label>();
			
		(*all_states[current]) += fm<Label>::arcs[i];
		fm<Label>::arcs.remove(i);
	}

	// Copy information from the set final_states
	for (i = fm<Label>::final_states.size()-1; i >= 0; i--)
	{
		// Find the state to be marked as final
		current = fm<Label>::final_states[i].value();
		
		// Create new states as needed
		while(current >= all_states.size())
			all_states += new atstate<Label>();
			
		(*all_states[current]).set_final(true);
		fm<Label>::final_states.remove(i);
	}

	attached = true;
}

template <class Label>
void
fcm<Label>::unattach()
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
			fm<Label>::arcs.disjoint_union(temp_arc);
		}
		if ((*all_states[i]).final())
			fm<Label>::final_states += i;
			
		delete all_states[i];
		all_states.remove(i);
	}

	attached = false;
}

template <class Label>
array<atstate<Label> * >
fcm<Label>::attach_inv()
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
