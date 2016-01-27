//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	July 1995

// Modified for fcm class October 2004

class state;
template <class Item> class set;

template <class Label>
ostream&
operator<<(ostream& os, const fcm<Label>& a)
{
	int		i, x;
	inst<Label>	t;
	set<state>	ss;

	// output maximum word length

	x = a.get_max();
	os << "l=" << x << '\n';

	// output start pseudo-instructions

	a.starts(ss);
	for (i=0; i<ss.size(); ++i)
	{
		t.make_start(ss[i]);
		os << t << "\n";
	}

	// output normal instructions

	for (i=0; i<a.size(); ++i)
		os << a[i] << "\n";

	// output final pseudo-instructions

	a.finals(ss);
	for (i=0; i<ss.size(); ++i)
	{
		t.make_final(ss[i]);
		os << t << "\n";
	}

	return os;
}
