/***************************************************************************
  Added in 3.3.1

  File:  classes/fl/alphabet.cpp     Brodie Champion + Marcus Trenton   July 2007
  --------

  void		fl<Label>::get_alphabet(set<Item> &s) const

  Description:
    This function computes the alphabet of the given finite language
  Parameters:
    set<Item> s - set of symbols forming the alphabet
  
 ***************************************************************************/

template<class Label>
void fl<Label>::get_alphabet(set<Label> &s) const{

	//Remove any symbols which are already in s.
	s.clear();
	
	//Loop over each word in the language
	for (int i = 0; i < words.size(); i++){

		//For each word, add each letter
		string<Label> current_word = words[i];

		for (int j = 0; j < current_word.size(); j++){

			s += current_word[j];
		}

	}
}
			
