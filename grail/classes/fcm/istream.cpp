//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	May 1993

// Modified for fcm class October 2004

template <class Label>
class fcm;

template <class Label>
istream&
operator>>(istream& is, fcm<Label>& a)
{
	inst<Label>		t;
	list<inst<Label> >	l;	
	int max = 0;
	char *tempLine = new char[4096];
	char temp;

	a.clear();

	while (is.peek() == '#')
		is.getline(tempLine, 4095);

	if (((char) is.get() == 'l')
		&& ((char) is.get() == '='))
	{
		temp = (char) is.get();
		while (temp != '\n')
		{
			max *= 10;
			max += atoi(&temp);
			temp = (char) is.get();
		}
	}

	a.set_max(max);

	while (is.peek() == '#')
		is.getline(tempLine, 4095);
	for (is >> t; !t.is_null(); is >> t)
	{
		if (t.is_start())
			a.start_states += t.get_sink();
		else
		if (t.is_final())
			a.final_states += t.get_source();
		else	
			l += t;
		while (is.peek() == '#')
			is.getline(tempLine, 4095);
	}

	a.arcs.from_list(l);
	return is;
}
