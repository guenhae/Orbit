/******************************************************************************************

File:	classes/afa/afacomplement.cpp
-----

Description:	
------------
	This file contains the definition of the following function:
		
			afa<T> afa<T>::complement() const

	This function is a public member of the template class afa
	(declared in afa.h).

Revision History:
-----------------
	X. Wu			Initial version of source code
	S. Huerter 08/12/98	Header and comments

******************************************************************************************/
/******************************************************************************************

			afa<T> afa<T>::complement() const

Description:
	This function is a public member of the template class afa (declared in afa.h).
	This function returns the afa accepting the complement of the language accepted by 
        "this" afa.

	This function can be called in the following way(s):
		comafa = afa.complement();		

	Return Value:
		afa<T>			- the afa accepting the complement of 
					  the language accepted by "this" afa;

******************************************************************************************/
//#include <math.h>
#include <cmath> //by SH 05/26/2005
//#include "afa.h"

template <class T> 
afa<T> afa<T>::complement() const
{
  afa<T> comafa;
  comafa.symbol = symbol;    //input symbol is the same as that of the orignal
  comafa.final = final;      //final states is the same as that of the orignal 
  comafa.states = states;    //have the same amount of states
  
  int snumber = symbol.size();
//cout<<"afa complement 1"<<endl;  
//copy the orignal function table to the newtable
  funct* comtable = new funct[states * snumber]; 
  for (int i = 0; i<states; i++)
    for (int j = 0; j<snumber; j++)
      comtable[i*snumber + j] = table[i*snumber + j];  //transitions are not 
						       //changed, just copied
  comafa.table = comtable;
  comtable = 0;

//head function is the logical NOT of the orignal head function
  comafa.head = head.not1(); //by SH 05/23/2005

  return comafa;
}
