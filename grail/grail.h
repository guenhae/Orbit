//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	December 1993

/*
#include	<stdlib.h>
#include	<iostream.h>
#include	<fstream.h>
#include	<strstream.h>
#include	<string.h>
#include	<ctype.h>
*/

#include	<stdlib.h>
#include     <iostream>
	using std::istream;
	using std::ostream;
#include	<fstream>
	using std::fstream;
#include <strstream>
	  using std::istrstream;
#include	<string.h>
#include	<ctype.h> //by SH 05/20/2005


#include		  "../classes/atstate/include.h" // Added in version 3.1.2
#include      "../classes/bits/include.h"
#include      "../classes/state/include.h"
#include      "../classes/array/include.h"
#include      "../classes/set/include.h"
#include      "../classes/pool/include.h"
#include      "../classes/list/include.h"
#include      "../classes/string/include.h"
#include      "../classes/pair/include.h"
#include      "../classes/inst/include.h"
#include      "../classes/re/include.h"
#include      "../classes/fm/include.h"
#include      "../classes/fcm/include.h" // Added in version 3.1
#include      "../classes/fl/include.h"
#include      "../classes/mealy/include.h"

char	string<char>::separator = '\0';
char	string<int>::separator = ' ';
char	string<unsigned int>::separator = ' ';
char	string<long>::separator = ' ';
char	string<unsigned long>::separator = ' ';
char	string<float>::separator = ' ';
char	string<double>::separator = ' ';

#ifdef		WATCOM
#include      "dosnames.h"
#endif

#ifndef		WATCOM
#include      "names.h"
#endif

typedef	void	(*PF)();			// pointer to function

extern	PF	set_new_handler(PF);

void 
new_error()
{
	cerr << "new failed\n";
	exit(-1);
}
