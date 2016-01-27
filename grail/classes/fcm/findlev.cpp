template<class Label>
class fm;

template<class Label>
array<int> 
fcm<Label>::find_levels()
// This function uses a breadth first traversal of the fcm to find 
// the level of each state.  This information is returned as an 
// array of integers.
// A level of -1 indicates that the state is unreachable.
{
   array<int> level;
	
	attach();

	if (maxlen == -1)
		maxlen = find_max();

   int n = all_states.size();
   int i, j, k;

	// Initialize the level array. 
   for (i = 0; i < n; i++)
      level += -1;

	int level_count = 1;

	level[fm<Label>::start_states[0].value()] = 0;

	array<int> current, next;
	
	// We are assuming there is one start state, since there are no
	// functions dealing with non-deterministic cover automata.
	current += fm<Label>::start_states[0].value();
	
	while (current.size() > 0)
	{
		for (i = 0; i < current.size(); i++)
			for (j = 0; j < (*all_states[current[i]]).size(); j++)
			{
				k = (*all_states[current[i]])[j].get_sink().value();
				if (level[k] == -1)
				{
					next += k;
					level[k] = level_count;
				}
			}

		current = next;
		next.clear();
		level_count++;

		if (level_count > maxlen)
			current.clear();
	}

   return level;
}


template<class Label>
array<int> 
fcm<Label>::find_ilevels()
// This function uses a breadth first traversal of the fcm to find 
// the inverse level of each state.  This information is returned as an 
// array of integers.
// An ilevel of -1 indicates that there is no path from that state
// to a final state.
{
	int i, j, k;
	
	attach();
	array<atstate<Label> * > inv = attach_inv();
	array<int> ilevel;

	array<int> current, next;

	for (i = 0; i < all_states.size(); i++)
	{
		if ((*all_states[i]).final())
		{
			current += i;
			ilevel += 0;
		}
		else
		{
			ilevel += -1;
		}
	}
	
	int ilevel_count = 1;
	while (current.size() > 0)
	{
		for (i = 0; i < current.size(); i++)
			for (j = 0; j < (*inv[current[i]]).size(); j++)
			{
				k = (*inv[current[i]])[j].get_sink().value();
				if (ilevel[k] == -1)
				{
					next += k;
					ilevel[k] = ilevel_count;
				}
			}

		current = next;
		next.clear();
		ilevel_count++;
	}

	return ilevel;
}
