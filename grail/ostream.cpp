//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1992


/***************************************************************************

  File:  classes/set/ostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      template <class Item>
      ostream& operator<<(ostream& os, const set<Item>& s)

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/05/30         Added header and comments


 ***************************************************************************/




/***************************************************************************

  template <class Item> ostream& operator<<(ostream& os, const set<Item>& s)

  Description:
    This function prints the contents of the set s onto the specified 
    output stream in the following format:
      Element1 Element2 Element3 ... ElementN

    (separated by spaces and followed by an end of line)

    The output stream must be valid and open before calling operator<<.

    operator<< must be defined for the class specified as Item.

    This function can be called in the following ways:
      operator<<(output_stream, set_to_print);
      output_stream << set_to_print;

  Parameters:
    ostream& os - the output stream
    const set<Item>& s - the set whose elements should be printed

  Return Value:
    ostream& - a reference to the output stream
  
 ***************************************************************************/

template <class Item>
ostream&
operator<<(ostream& os, const set<Item>& s)
{
	for (int i=0; i<s.size(); ++i)
		os << s[i] << " ";
	return os << "\n";
}








