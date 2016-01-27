// TODO: 
//  * declare in classes/re/fm.h 
//  * include this in.... wherever the source files are included!    
//  * Write the shuffle operation
//
/***************************************************************************

  File:  classes/fm/shuffle.cpp     Brodie Champion + Marcus Trenton   June 2007
  --------

  void fm<Label>::shuffle(const fm<Label>& a, const fm<Label> b)

  Description:
    This function computes the shuffle of two regular languages. 
	We store an NFA for the shuffle in this fm.

    This function can be called in the following way:
      this_fm.shuffle(first_fm, second_fm);

  Parameters:
    const fm<Label>& a - the first fm with which to compute cross product
    const fm<Label>& b - the second fm with which to compute cross product

  Return Value:  none
  
 ***************************************************************************/

template <class Label>
void fm<Label>::shuffle(const fm<Label>& a, const fm<Label> b)
{
	state			s1;
	state			s2;
	inst<Label>		t;
	fm<Label>		result;
	
	// clear result and this fm
	result.clear();
	clear();

	//Calculate the number of states in a and in b
	int num_states_a = a.number_of_states();
	int num_states_b = b.number_of_states();

	// Copies the arcs occuring in automaton 'a'
	for (int j=0; j< a.size(); j++)
	{
		int v1 = a[j].get_source().value(); 
		int v2 = a[j].get_sink().value();   
		for (int k=0; k< num_states_b; k++)
		{
			s1 = v1 + k * num_states_a;
			s2 = v2 + k * num_states_a;
			t.assign(s1, a[j].get_label() , s2);

			result.arcs.disjoint_union(t);
		}
	}

	// Copies the arcs occuring in automaton 'b'
	for (int j=0; j< b.size(); j++)
	{
		int v1 = b[j].get_source().value(); 
		int v2 = b[j].get_sink().value();   
		for (int k=0; k< num_states_a; k++)
		{
			s1 = v1 * num_states_a + k;
			s2 = v2 * num_states_a + k;
			t.assign(s1, b[j].get_label(), s2);

			result.arcs.disjoint_union(t);
		}
	}
	
	// start and final states
	for (int i=0; i<a.start_states.size(); i++)
	{
		int v1 = a.start_states[i].value(); 
		for (int j=0; j<b.start_states.size(); j++)
		{
			int v2 = b.start_states[j].value();
			s1 = v1 + v2 * num_states_a;	//I DON'T KNOW, MAYBE WRONG? BUT WILL COMPILE :D
			result.start_states += s1;
		} 
	}

	for (int i=0; i<a.final_states.size(); i++)
	{
		int v1 = a.final_states[i].value(); 
		for (int j=0; j<b.final_states.size(); j++)
		{
			int v2 = b.final_states[j].value();
			s2 = v1 + v2 * num_states_a; //MAYBE RIGHT??! ^_^
			result.final_states += s2;
		} 
	}

	*this = result;
}
