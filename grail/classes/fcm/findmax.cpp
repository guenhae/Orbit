template<class Label>
class fm;

template<class Label>
int 
fcm<Label>::find_max()
{
	int i, j, k;
	
	attach();

	array<int> ilevel = find_ilevels();
	
	int n = all_states.size();

	array<int> current, next;

	current += fm<Label>::start_states[0].value();

	int max = -1;

	while (current.size() > 0)
	{
		for (i = 0; i < current.size(); i++)
			for (j = 0; j < (*all_states[current[i]]).size(); j++)
			{
				k = (*all_states[current[i]])[j].get_sink().value();
				if ((k != current[i]) && (ilevel[k] >= 0))
				{
					next += k;
				}
			}

		next.unique();
		
		current = next;
		next.clear();
		max++;
	}

	return max;
}
