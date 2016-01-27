//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1994

template<> char	re<char>::re_star = '*';
template<> char	re<char>::re_plus = '+';
template<> char	re<char>::re_cat = '\0';
template<> char*	re<char>::re_estring = "\"\"";
template<> char	re<char>::re_lparen = '(';
template<> char	re<char>::re_rparen = ')';
template<> char*	re<char>::re_eset = "{}";
template<> char	re<char>::re_left_delimiter = ' ';
template<> char	re<char>::re_right_delimiter = ' ';
template<> char	re<char>::re_left_symbol_delimiter = '\0';
template<> char	re<char>::re_right_symbol_delimiter = '\0';

template<> char	string<re<char> >::separator = ' ';
