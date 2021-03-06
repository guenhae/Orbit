//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1995


/***************************************************************************

  File:  classes/fl/ostream.cpp
  -----

  Description:
  ------------
    This file contains the definition of the following function:
      template <class Item> ostream& operator<<(ostream& os, const fl<Item>& s)


  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/05         Added header and comments

 ***************************************************************************/




/***************************************************************************

  template <class Item> ostream& operator<<(ostream& os, const fl<Item>& s)

  Description:
    This function allows an fl (finite language) to be outputted to a
    stream.  Each word is outputted using operator<< for string<Item>
    followed by "\n".  This will normally result in output of one word
    per line.  The output stream should be valid and open before calling
    this function.  The function returns a reference to the output stream.

    This function can be called in the following ways:
      operator<<(output_stream, language);
      output_stream << language;

  Parameters:
    ostream& os - the output stream
    const fl<Item>&s - the finite language to be outputted.

  Return Value:
    ostream& - a reference to the output stream.

  
 ***************************************************************************/

template <class Item>
ostream& operator<<(ostream& os, const fl<Item>& s)
{
	for (int i=0; i<s.size(); ++i)
		os << s.words[i] << "\n";
	return os;
}
