/*
#include	<stdlib.h>
#include	<iostream.h>
#include	<fstream.h>
#include	<strstream.h>
#include	<string.h>
#include	<ctype.h>
*/
#include<stdio.h>
#include	<stdlib.h>
#include     <iostream>
	using std::cerr;
	using std::istream;
	using std::ostream;
	using std::cout;

#include	<fstream>
	using std::fstream;
	using std::ifstream;
#include <strstream>
	using std::istrstream;
#include	<string.h>
#include	<ctype.h>  //by SH 05/20/2005
#include	<stdlib.h>
	
#include      "classes\atstate\include.h" // Added in 3.1.2
#include      "classes\bits\include.h"
#include      "classes\state\include.h"
#include      "classes\array\include.h"
#include      "classes\set\include.h"
#include      "classes\pool\include.h"
#include      "classes\list\include.h"
#include      "classes\string\include.h"
#include      "classes\pair\include.h"
#include      "classes\inst\include.h"
#include      "classes\re\include.h"
#include      "classes\fcm\include.h" // Added in 3.1
#include      "classes\fm\include.h"
#include      "classes\fl\include.h"
#include      "classes\mealy\include.h"
#include      "classes\afa\dnf\include.h"
#include      "classes\afa\include.h"
//#include "atstate.h"
//#include "atstate.cpp"
//#include "bits.h"
//#include "assign.cpp"
//#include "bits.cpp"
//#include "clear.cpp"
//#include "eq.cpp"
//#include "extract.cpp"
//#include "gt.cpp"
//#include "increase.cpp"
//#include "index.cpp"
//#include "iterate.cpp"
//#include "lt.cpp"
//#include "member.cpp"
//#include "pluseq.cpp"
//#include	"state.h"
//#include	"istream.cpp"
//#include	"minuseq.cpp"
//#include	"array.h"
//#include	"defs.h"
//#include	"assign.cpp"
//#include	"compare.cpp"
//#include	"contain.cpp"
//#include	"eq.cpp"
//#include	"member.cpp"
//#include	"array.cpp"
//#include	"lt.cpp"
//#include	"merge.cpp"
//#include	"minuseq.cpp"
//#include	"pluseq.cpp"
//#include	"remove.cpp"
//#include	"sort.cpp"
//#include	"unique.cpp"
//#include        "fistream.cpp"
//#include        "fostream.cpp"
//#include	"set.h"
//#include	"contain.cpp"
//#include	"eq.cpp"
//#include	"list.cpp"
//#include	"lt.cpp"
//#include	"intersct.cpp"
//#include	"member.cpp"
//#include	"minuseq.cpp"
//#include	"pluseq.cpp"








template<> char	string<char>::separator = '\0';
template<> char	string<int>::separator = ' ';
template<> char	string<unsigned int>::separator = ' ';
template<> char	string<long>::separator = ' ';
template<> char	string<unsigned long>::separator = ' ';
template<> char	string<float>::separator = ' ';
template<> char	string<double>::separator = ' ';

#ifdef          WATCOM
#include      "dosnames.h"
#endif
 
#ifndef         WATCOM
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
