template <class Label>
int atstate<Label>::operator==(const atstate &s) const
{
	if ((is_final) != (s.is_final))
		return 0;
	if (transitions.size() != s.transitions.size())
		return 0;

	int i;
	for (i = 0; i < transitions.size(); i++)
	{
		if ( (transitions[i].get_label() != s.transitions[i].get_label())
			|| (transitions[i].get_sink() != s.transitions[i].get_sink()) )
			return 0;
	}

	return 1;
}

template <class Label>
int atstate<Label>::operator<(const atstate &s) const
{
	if ((!is_final) && (s.is_final))
		return 1;
	else if ((is_final) && (!s.is_final))
		return 0;

	if (transitions.size() < s.transitions.size())
		return 1;
	else if (transitions.size() > s.transitions.size())
		return 0;

	atstate temp = s;
	int i;
	extern int num;
	for (i = 0; i < temp.size(); i++)
		temp[i].assign(num, temp[i].get_label(),
			temp[i].get_sink().value());

	transitions.sort();
	temp.transitions.sort();
	for (i = 0; i < transitions.size(); i++)
	{
		if (transitions[i] < temp.transitions[i])
			return 1;
		else if (transitions[i] > temp.transitions[i])
			return 0;
	}

	return 0;
}
