//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1993

// Modified from canonical_numbering() January 2005

template <class Label>
int
fm<Label>::order()
{
	if (canonical_numbering() == 0)
		return 0;

	int i, j, k, l;
	attach();
	fm<Label> new_fm;
	array<int> numbered, new_number;
	array<int> in_degree;
	set<state> new_start_states, new_final_states;

	for (i = 0; i < all_states.size(); i++)
		in_degree += 0;

	for (i = 0; i < all_states.size(); i++)
		for (j = 0; j < (*all_states[i]).size(); j++)
			in_degree[(*all_states[i])[j].get_sink().value()]++;

	array<int> current, next;
	current += start_states[0].value();

	while (current.size() > 0)
	{
		for (i = 0; i < current.size(); i++)
		{
			for (j = 0; j < (*all_states[current[i]]).size(); j++)
			{
				k = (*all_states[current[i]])[j].get_sink().value();
				in_degree[k]--;
				if (in_degree[k] == 0)
					next += k;
			}

			numbered += current[i];
		}
		
		next.unique();
		current = next;
		next.clear();
	}

	if (numbered.size() < all_states.size())
		for (i = 0; i < all_states.size(); i++)
			if (in_degree[i] != 0)
				numbered += i;

	for (i = 0; i < numbered.size(); i++)
	{
		if (start_states.member(numbered[i]) != -1)
			new_start_states += i;
			
		if ((*all_states[numbered[i]]).final())
			new_final_states += i;
	}

	for (i = 0; i < all_states.size(); i++)
		new_number += numbered.member(i);

	for (i = 0; i < all_states.size(); i++)
	{
		k = new_number[i];
		for (j = 0; j < (*all_states[i]).size(); j++)
		{
			l = new_number[(*all_states[i])[j].get_sink().value()];
			(*all_states[i])[j].assign(k, (*all_states[i])[j].get_label(), l);
		}
	}
	
	unattach();
			
	start_states = new_start_states;
	final_states = new_final_states;

	arcs.sort();

	return 1;
}
