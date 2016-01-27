//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1994


/***************************************************************************

File:  classes/re/fmtore2.cpp
-----

Description:
------------
This file contains the definition of the following function:
void re<Label>::fmtore(fm<Label>& f)

This function is a public member of the template class re (declared
in classes/re/re.h).

Revision History:
-----------------
The Grail Project               Initial version of source code
M.Hoeberechts  98/06/08         Added header and comments


***************************************************************************/




/***************************************************************************

void re<Label>::fmtore(fm<Label>& f)

Description:
This function is a public member of the template class re (declared
in classes/re/re.h).  This function converts the parameter finite
machine to a minimal regular expression.  The basic idea of the algorithm
is to eliminate one state at a time from the finite machine by replacing
the transitions and and out of the state which regular expressions which
represent the possible paths through the state.  The algorithm works
approximately as follows:

- make a copy of f (called a) which has regular expressions on the arcs.
- if f contains a start state which is final, set flag for empty string.
- for each state in f:
- gather all the transitions into and out of the current state and
eliminate them from a.
- create a regular expression which represents self loops (if any) on
the current state.
- if there is only one transition into the current state,
- catenate the union of the labels on the input transitions onto the
regular expression which represents the self loops.
- for each output transition, add a transition to a which links the
source state of the input transition to the sink state of the
output transition with a label consisting of the regular expression
which was just built.
- if there is more than one transition into the current state,
- create a regular expression in the manner described above for
each possible input-output transition combination and add the
result to a.
- create the final regular expression by taking the union of all the
expressions which are left in a.
- add the empty string to the re if required.
- call minimize() on the regular expression.


This function can be called in the following way:
this_re.fmtore(machine);

Parameters:
fm<Label>& f - the finite machine to convert to a regular expression

Return Value:  none

***************************************************************************/

#include <stack>
#include"../stenum.h" //by UGO 10/20/2006 
state			start;
state			end;
template <class Label>
void find_scc(fm<Label>& f,set<set<state>>& orbits){
	set<state> next; 
	f.states(next);
	int index = 0;
	set<set<state>> scc;
	std::stack<state> st;
	for (int i = 0; i < next.size(); ++i){
		if (next[i].index == -1){
			state& temp = next[i];
			strongconnect(next,scc, st, f, next[i], index);
		}
	}
	cout << scc.size() << " Strongly Connected Components detected" << endl;
	for (int i = 0; i < scc.size(); ++i){
		set<state> entrances;
		set<state> ingates;
		set<state> outgates;
		set<state> destinations;
		set<state> in_and_dest;
		bool orbit = true;
		for (int j = 0; j < scc[i].size(); ++j){
			state& s = scc[i][j];
			set<state> s_source;
			set<state> s_sink;
			fm<Label> subfm1;
			f.select(s, SINK, subfm1);
			subfm1.sources(s_source);
			s_source -= scc[i];
	//		if (s_source.member(start)!=-1) s_source -= start;
			fm<Label> subfm2;
			f.select(s, SOURCE, subfm2);
			subfm2.sinks(s_sink);
	//		if (s_sink.member(end)!=-1) s_sink -= end;
			s_sink -= scc[i];
			if (s_source.size() != 0){ // s is in-gate
				if (entrances.size() == 0){
					entrances += s_source;
				}
				else if (entrances != s_source){
					orbit = false;
					break;
				}
				ingates += s;

			}
			if (s_sink.size() != 0){ // s is out-gate
				if (destinations.size() == 0){
					destinations += s_sink;
				}
				else if (destinations != s_sink){
					orbit = false;
					break;
				}
				outgates += s;

			}
		}

		if (outgates.size() == 0 || ingates.size() == 0 || entrances.size() == 0 || destinations.size() == 0) orbit = false;
		if (orbit == false) continue;
		in_and_dest += ingates;
		in_and_dest += destinations;
		for (int j = 0; j < entrances.size(); j++){
			state& s = entrances[j];
			fm<Label> subfm3;
			f.select(s, SOURCE, subfm3);
			set<state> s_sink;
			subfm3.sinks(s_sink);
			if (s_sink != in_and_dest) orbit = false;
		}
		for (int j = 0; j < outgates.size(); j++){
			state& s = outgates[j];
			fm<Label> subfm3;
			f.select(s, SOURCE, subfm3);
			set<state> s_sink;
			subfm3.sinks(s_sink);
			if (s_sink != in_and_dest) orbit = false;
		}
		if (orbit == false) continue;
		for (int j = 0; j < ingates.size(); j++){
			state& s = ingates[j];
			fm<Label> subfm3;
			f.select(s, SINK, subfm3);
			set<state> s_source;
			subfm3.sources(s_source);
			if ((s_source > outgates) == false){
				orbit = false;
				break;
			}
			set<inst<Label>> arc;
			subfm3.get_arcs(arc);
			inst<Label>& tempinst = arc[0];
			Label	 label = tempinst.get_label();
			for (int k = 1; k < arc.size(); k++){
				inst<Label>& tempinst = arc[k];
				if (label != tempinst.get_label()){
					orbit = false;
					break;
				}
			}
		}
		if (orbit == false) break;
		for (int j = 0; j < destinations.size(); j++){
			state& s = destinations[j];
			fm<Label> subfm4;
			f.select(s, SINK, subfm4);
			set<state> s_source;
			subfm4.sources(s_source);
			if ((s_source > outgates) && (s_source > entrances)){
				set<inst<Label>> arc;
				subfm4.get_arcs(arc);
				inst<Label>& tempinst = arc[0];
				Label label = tempinst.get_label();
				for (int k = 1; k < arc.size(); k++){
					inst<Label>& tempinst = arc[k];
					if (label != tempinst.get_label()){
						orbit = false;
						break;
					}
				}
			}
			else{
				orbit = false;
				break;
			}
		}
		if (orbit == true) orbits += scc[i];
	}
	cout << orbits.size() << " Orbits detected" << endl;
}

state& find_state(set<state>& next, int number){
	for (int i = 0; i < next.size(); i++){
		if (next[i].value() == number) return next[i];
	}
}

template <class Label>
void strongconnect(set<state>& next,set<set<state>>& scc,std::stack<state> &st,fm<Label> &f,state &v,int& index){
	v.index = index; 
	v.lowlink = index;
	index += 1;
	v.on_stack = true;
	st.push(v);
	fm<Label> subfm1;
	f.select(v, SOURCE, subfm1);

	set<state> sink;

	subfm1.sinks(sink);
	for (int j = 0; j < sink.size(); j++){
		state& temp = sink[j];
		if (sink[j]==end) break;
		state& sinkstate = find_state(next,sink[j].value());
		if (sinkstate == v) continue;
		if (sinkstate.index == -1){
			strongconnect(next,scc,st,f, sinkstate, index);
			v.lowlink = (v.lowlink < sinkstate.lowlink ? v.lowlink : sinkstate.lowlink);
		}
		else if (sinkstate.on_stack){
			v.lowlink = (v.lowlink < sinkstate.index ? v.lowlink : sinkstate.index);
		}

	}

	if (v.lowlink == v.index){ // if v is a root node
		set<state> newscc;
		state& w = find_state(next,st.top().value());
		st.pop();
		w.on_stack = false;
		newscc += w;
		while (v != w){
			state &w = find_state(next, st.top().value());
			st.pop();
			w.on_stack = false;
			newscc += w;
			if (v == w) break;
		}

		scc += newscc;
	}

}

template <class Label>
void
get_entrance(fm<Label>& f, set<state>& or,set<state>& entrance){
	entrance.clear();
	for (int i = 0; i < or.size(); i++){
		fm<Label> subfm1;
		set<state> source;
		state& o= or[i];
		f.select(o, SINK, subfm1);
		subfm1.sources(source);
		source -= start;
		source -= end;
		source -= or;
		entrance += source;
	}
}

template <class Label>
void
get_destinations(fm<Label>& f, set<state>& or, set<state>& destinations){
	destinations.clear();
	for (int i = 0; i < or.size(); i++){
		fm<Label> subfm1;
		set<state> sink;
		state& o = or[i];
		f.select(o, SOURCE, subfm1);
		subfm1.sinks(sink);
		sink -= start;
		sink -= end;
		sink -= or;
		destinations += sink;
	}
}

template <class Label>
void
merge(fm<Label>&f, state& from, state& to){
	fm<Label> subfm1;
	f.select(from, SINK, subfm1);
	for (int i = 0; i < subfm1.size(); i++){
		inst<Label> ins = subfm1[i];
		inst<Label> new_ins;
		new_ins.assign(ins.get_source(), ins.get_label(), to);
		f.remove(from);
		f.add_instruction(new_ins);
	}
}

template <class Label>
void get_ingates(fm<Label>& f, set<state>& orbits,set<state>& ingates){
	ingates.clear();
	for (int i = 0; i < orbits.size(); i++){
		state& tempstate = orbits[i];
		fm<Label> subfm1;
		f.select(tempstate, SINK, subfm1);
		set<state> sources;
		subfm1.sources(sources);
		sources -= orbits;
		if (sources.size() != 0) ingates += tempstate; 
	}
}

template <class Label>
void get_outgates(fm<Label>& f, set<state>& orbits,set<state>& outgates){
	outgates.clear();
	for (int i = 0; i < orbits.size(); i++){
		state& tempstate = orbits[i];
		fm<Label> subfm1;
		f.select(tempstate, SOURCE, subfm1);
		set<state> sinks;
		subfm1.sinks(sinks);
		sinks -= orbits;
		if (sinks.size() != 0) outgates += tempstate;
	}
}

template <class Label>
void
orbit_process(fm<Label>& f, set<set<state>>& orbits, fm<re<Label>>& a,int &max_index){
	for (int i = 0; i < orbits.size(); i++){
		set<state>& or = orbits[i];
		set<state> entrance;
		get_entrance(f, or, entrance);
		state& first_state = entrance[0];
		for (int j = 1; j < entrance.size(); j++){
			merge(f, entrance[j], first_state);
		}
	}
	for (int i = 0; i < orbits.size(); i++){
		fm<Label> tempf;
		set<state>& or = orbits[i];
		set<state> ingates;
		set<state> outgates;
		set<state> entrance;
		set<state> destinations;
		state& first_state = entrance[0];
		state new_dest; set<state> new_finals;
		new_dest = ++max_index;

		get_entrance(f, or, entrance);
		get_destinations(f, or, destinations);
		get_ingates(f, or, ingates);
		get_outgates(f, or, outgates);
		tempf.set_starts(entrance);
		tempf.set_finals(outgates);
		for (int j = 0; j < or.size(); j++){
			state& tempstate = or[j];
			fm<Label> subfm1;
			f.select(tempstate, EITHER, subfm1);
			for (int k = 0; k < subfm1.size(); k++){
				tempf.add_instruction(subfm1[k]);
			}
		}
		for (int j = 0; j < destinations.size(); j++){
			state& temp = destinations[j];
			fm<Label> subfm;
			f.select(temp, SINK, subfm);
			inst<Label>& tempinst = subfm[0];
			re<Label> r;
			r.make_symbol(tempinst.get_label());
			inst<re<Label>> tnew;
			tnew.assign(new_dest, r, temp);
			a.add_instruction(tnew);
			tempf -= subfm;
			f -= subfm;
		}

		fm<Label> subfm2;
		f.select(first_state, SOURCE, subfm2);
		f -= subfm2;
		f -= tempf;
		fm<Label> tempf2;
		set<inst<Label>> tempinsts;
		for (int j = 0; j < tempf.size(); j++){
			inst<Label> tempinst = tempf[j];
			if (outgates.member(tempinst.get_source()) != -1 && ingates.member(tempinst.get_sink()) != -1){
				tempf2.add_instruction(tempinst);
				tempinsts += tempinst;
			}
		}
		tempf -= tempf2;
		re<Label> tempre;	
		tempre.fmtore2(tempf);
		tempre.star();
		cout << "MIDDLE : " << tempre << endl;
		
		
		inst<re<Label>> tnew;
		tnew.assign(first_state, tempre, new_dest);
		a.add_instruction(tnew);
		
	}
}

template <class Label>
void
re<Label>::fmtore2(fm<Label> f)
{
	int			max_index = 0;
	int			i;
	int			j;
	int			k;
	int			empty_string = 0;
	state		big;
	re<Label>		r;
	re<Label>		s;
	re<Label>		q;
	inst<re<Label> >	tnew;
	fm<re<Label> >		a;
	set<state>		next;
	set<state>		starts;
	set<state>		finals;
	set<state>		targets;
	set<set<state>>		orbits;
	fm<re<Label> >		subfm1;
	fm<re<Label> >		subfm2;
	fm<re<Label> >		subfm3;
	re<Label>			middle;
	set<re<Label> >		middles;
	set<re<Label> >		sources;
	set<re<Label> >		sinks;
	
	// use only the reachable fm

	f.reachable_fm();
	f.starts(starts);
	f.finals(finals);
	max_index = f.max_state().value();
	find_scc(f, orbits);
	if (orbits.size() != 0)	orbit_process(f, orbits, a,max_index);

	clear();
	// if no final states, we're done
	if (finals.size() < 1)
		return;

	// copy instructions, converting Label to re<Label> 
	for (i = 0; i<f.size(); ++i)
	{
		inst<Label>& temp = f[i]; 
		r.make_symbol(f[i].get_label());
		tnew.assign(f[i].get_source(), r, f[i].get_sink());
		a.add_instruction(tnew);
	}
	// add pseudo-instructions 
	big = ++max_index;
	start = big;
	r.clear();
	for (i = 0; i<starts.size(); ++i)
	{
		tnew.assign(big, r, starts[i]);
		a.add_instruction(tnew);
	}

	big = big.value() + 1;
	end = big;
	for (i = 0; i<finals.size(); ++i)
	{
		tnew.assign(finals[i], r, big);	
		a.add_instruction(tnew);
	}

	// check for empty string
	next.intersect(starts, finals);

	if (next.size() > 0)
		empty_string = 1;

	// eliminate each state.
	//f.states(next);
	a.states(next);
	next -= start;	next -= end;
	for (i = 0; i<next.size(); ++i)
	{
		// cout << "doing state " << next[i] << endl;
		state& tempstate = next[i];
		// get all arcs from or to this state
		a.select(next[i], EITHER, subfm1);

		//  cout << "arcs include " << subfm1;

		// delete them from machine

		a -= subfm1;

		// compute re of self-looping arcs, avoiding duplicates 
		subfm2.clear();
		for (j = 0; j<subfm1.size(); ++j)
		if (subfm1[j].get_source() == next[i] &&
			subfm1[j].get_sink() == next[i])
			subfm2.add_instruction(subfm1[j]);

		middles.clear();
		for (j = 0; j<subfm2.size(); ++j)
			middles += subfm2[j].get_label();

		middle.clear();
		for (j = 0; j<middles.size(); ++j)
			middle += middles[j];
		middle.star();

		// remove the self loops
		subfm1 -= subfm2;

		// select lead-in and lead-out arcs
		subfm1.select(next[i], SOURCE, subfm2);
		subfm1.select(next[i], SINK, subfm3);

		// cout << "subfm2 is " << subfm2;
		// cout << "subfm3 is " << subfm3;

		// for each non self-loop, create the re
		targets.clear();
		for (j = 0; j<subfm3.size(); ++j)
			targets += subfm3[j].get_source();

		// if only one input state, compute union of
		// its instruction labels
		if (targets.size() == 1)
		{
			// get all the transitions in the current state
			middles.clear();
			for (j = 0; j<subfm3.size(); ++j)
				middles += subfm3[j].get_label();

			// catenate the union of all the input transitions
			//  onto the self loops
			r.clear();
			for (j = 0; j<middles.size(); ++j)
				r += middles[j];
			r ^= middle;

			// gather all the states on the ends of the out
			//  transitions (targets not used???)
			targets.clear();
			for (k = 0; k<subfm2.size(); ++k)
				targets += subfm2[k].get_sink();

			// add regular expressions to a which represent each
			//  of the possible paths which go through the current
			//  state
			for (k = 0; k<subfm2.size(); ++k)
			{
				q = r;
				q ^= subfm2[k].get_label();
				if (!q.is_clear())
				{
					tnew.assign(subfm3[0].get_source(), q,
						subfm2[k].get_sink());
					a.add_instruction(tnew);
				}
			}
		}
		else
			// loop through all the transitions into the current state
		for (j = 0; j<subfm3.size(); ++j)
		{
			// catenate the self loops onto the current transition
			r = subfm3[j].get_label();
			r ^= middle;

			// get all the target states
			targets.clear();
			for (k = 0; k<subfm2.size(); ++k)
				targets += subfm2[k].get_sink();

			if (targets.size() == 1)
			{
				// catenate the union of all the output
				//  transitions onto the current contents of r
				s.clear();
				middles.clear();
				for (k = 0; k<subfm2.size(); ++k)
					middles += subfm2[k].get_label();
				for (k = 0; k<middles.size(); ++k)
					s += middles[k];
				r ^= s;

				// add the regular expression which represents
				//  the possible transitions from input state
				//  j to the one output state
				if (!r.is_clear())
				{
					tnew.assign(subfm3[j].get_source(), r,
						subfm2[0].get_sink());
					a.add_instruction(tnew);
				}
			}
			else
			for (k = 0; k<subfm2.size(); ++k)
			{
				// for each output transition add a regular
				//  expression representing the possible paths
				//  from the current input state to it to a.
				q = r;
				q ^= subfm2[k].get_label();
				if (!q.is_clear())
				{
					tnew.assign(subfm3[j].get_source(), q,
						subfm2[k].get_sink());
					a.add_instruction(tnew);
				}
			}
		}
	}

	// now compute the final re as union of remaining re's
	for (i = 0; i<a.size(); ++i)
		*this += a[i].get_label();

	// add empty string if any start state was also final
	if (empty_string)
		*this += r.make_empty_string();

	minimize();
}
