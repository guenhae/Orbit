//	This code copyright (c) by the Grail project. 
//	No commercial use permitted without written consent.  
//	February 1995 
 
template <class Input, class Output> 
mealy<Input, Output>& 
mealy<Input, Output>::operator=(const mealy<Input, Output>& f) 
{ 
	// check for self-assignment 
 
	if (this == &f) 
		return *this; 
 
	this->arcs = f.arcs; 
	this->start_states = f.start_states; 
	this->final_states = f.final_states; 
 
	return *this; 
} 
