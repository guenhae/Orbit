//	This code copyright (c) by the Grail project.
//	No commercial use permitted without written consent. 
//	January 1994


/***************************************************************************

  File:  classes/re/print.cpp
  -----

  Description:
  ------------
    This file contains the definitions of the following functions:

      for ATT compiler only:
        void symbol_exp<S>::print(ostream& os, int) const
        void empty_set<S>::print(ostream& os, int) const
        void empty_string<S>::print(ostream& os, int) const
        void star_exp<S>::print(ostream& os, int) const

       for all compilers:
         void plus_exp<S>::print(ostream& os, int priority) const
         void cat_exp<S>::print(ostream& os, int priority) const

    These functions are public members of the template classes declared 
    in classes/re/re.h (re and subclasses of subexp).

  Revision History:
  -----------------
    The Grail Project               Initial version of source code
    M.Hoeberechts  98/06/09         Added header and comments


 ***************************************************************************/




/***************************************************************************

            void symbol_exp<S>::print(ostream& os, int) const
            void empty_set<S>::print(ostream& os, int) const
            void empty_string<S>::print(ostream& os, int) const
            void star_exp<S>::print(ostream& os, int) const

  Description:
    These functions are public members of template classes declared 
    in classes/re/re.h.  These function definitions are necessary for the
    ATT compiler only (it seems they cannot be left as inline functions).
    Each prints the symbol which corresponds to the type of subexpression
    represented by object.

    These functions can be called in the following ways:
      this_subexp.print(output_stream, i);

  Parameters:
    ostream& os - the output stream
    int - the priority of the operator (not used in these four functions)

  Return Value:  none
  
 ***************************************************************************/

#ifdef	ATT

template <class S>
void
symbol_exp<S>::print(ostream& os, int) const
{
	os << content;
}

template <class S>
void
empty_set<S>::print(ostream& os, int) const
{
	os << re<S>::re_eset;
}

template <class S>
void
empty_string<S>::print(ostream& os, int) const
{
	os << re<S>::re_estring;
}

template <class S>
void
star_exp<S>::print(ostream& os, int) const
{
	left->print(os, 3); 
	os << re<S>::re_star;
}

#endif




/***************************************************************************

         void plus_exp<S>::print(ostream& os, int priority) const

  Description:
    This function is a public member of template class plus_exp (declared 
    in classes/re/re.h).  This function prints an expression which is a
    union of two other expressions.  priority is used to determine whether or
    not brackets are needed around the expression.  If this plus_exp is part
    of an expression with higher priority than itself (as determined by
    the value of priority:  star = 3, cat = 2 and plus = 1) then the left
    and right expressions are put in brackets.  For example, "(a+b)*" will
    be correctly outputted with brackets rather than "a+b*".  To output
    the left and right halves of the plus_exp, this function calls
    left->print(os, 1) and right->print(os, 1).  Note that the 1 indicates
    the priority of plus.  The output stream must be valid and open before
    calling this function.

    This function can be called in the following way:
      this_plus_exp.print(output_stream, i);

  Parameters:
    ostream& os - the output stream
    int - the priority of the operator which is calling this function.

  Return Value:  none
  
 ***************************************************************************/

template <class S>
void
plus_exp<S>::print(ostream& os, int priority) const
{
	if (priority > 1 && re<S>::re_lparen != '\0')
		os << re<S>::re_lparen;
	if (left != 0) left->print(os, 1);
	os << re<S>::re_plus;
	if (right != 0) right->print(os, 1);
	if (priority > 1 && re<S>::re_rparen != '\0')
		os << re<S>::re_rparen;
}




/***************************************************************************

         void cat_exp<S>::print(ostream& os, int priority) const

  Description:
    This function is a public member of template class cat_exp (declared 
    in classes/re/re.h).  This function prints an expression which is a
    catenation of two other expressions.  priority is used to determine 
    whether or not brackets are needed around the expression.  If this cat_exp
    is part of an expression with higher priority than itself (as determined by
    the value of priority:  star = 3, cat = 2 and plus = 1) then the left
    and right expressions are put in brackets.  For example, "(ab)*" will
    be correctly outputted with brackets rather than "ab*".  To output
    the left and right halves of the cat_exp, this function calls
    left->print(os, 2) and right->print(os, 2).  Note that the 2 indicates
    the priority of cat.  The output stream must be valid and open before
    calling this function.

    This function can be called in the following way:
      this_cat_exp.print(output_stream, i);

  Parameters:
    ostream& os - the output stream
    int - the priority of the operator which is calling this function.

  Return Value:  none
  
 ***************************************************************************/

template <class S>
void
cat_exp<S>::print(ostream& os, int priority) const
{
	if (priority > 2 && re<S>::re_lparen != '\0')
		os << re<S>::re_lparen;
	if (left != 0) left->print(os, 2);
	if (re<S>::re_cat != '\0')
		os << re<S>::re_cat; 
	if (right != 0) right->print(os, 2);
	if (priority > 2 && re<S>::re_rparen != '\0')
		os << re<S>::re_rparen;
}


