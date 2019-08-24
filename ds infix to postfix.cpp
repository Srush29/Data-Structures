#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
const int MAX = 50 ;
class infix
{
    char target[MAX], stk[MAX] ;
    char *s, *t ;
    int top ;
    public :
    infix( )
    {
	top = -1 ;
	strcpy ( target, "" ) ;
	strcpy ( stk, "" ) ;
	t = target ;
	s = ""  ;
    }
    void setexpr ( char *str )
    {
	s = str ;
    }
    void push ( char c )
    {
	if ( top == MAX )
		cout << "\nStack is full\n" ;
	else
	{
		top++ ;
		stk[top] = c ;
	}
    }
    char pop( )
    {
	if ( top == -1 )
	{
		cout << "\nStack is empty\n" ;
		return -1 ;
	}
	else
	{
		char item = stk[top] ;
		top-- ;
		return item ;
	}
    }
    void convert( )
    {
	while ( *s )
	{
		if ( *s == ' ' || *s == '\t' )
		{
			s++ ;
			continue ;
		}
		if ( isdigit ( *s ) || isalpha ( *s ) )
		{
			while ( isdigit ( *s ) || isalpha ( *s ) )
			{
				*t = *s ;
				s++ ;
				t++ ;
			}
		}
		if ( *s == '(' )
		{
			push ( *s ) ;
			s++ ;
		}
		char opr ;
		if ( *s == '*' || *s == '+' || *s == '/' || *s == '%' || *s == '-' || *s == '$' )
		{
			if ( top != -1 )
			{
				opr = pop( ) ;
				while ( priority ( opr ) >= priority ( *s ) )
				{
					*t = opr ;
					t++ ;
					opr = pop( ) ;
				}
				push ( opr ) ;
				push ( *s ) ;
			}
			else
				push ( *s ) ;
			s++ ;
		}
		if ( *s == ')' )
		{
			opr = pop( ) ;
			while ( ( opr ) != '(' )
			{
				*t = opr ;
				t++ ;
				opr =  pop( ) ;
			}
			s++ ;
		}
	}
	while ( top != -1 )
	{
		char opr = pop( ) ;
		*t = opr ;
		t++ ;
	}
	*t = '\0' ;
    }
int priority ( char c )
{
	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}
    void show( )
    {
	cout << target ;
    }
};
    int main( )
{
	char express[MAX] ;
	infix obj ;

	cout << "\nEnter an expression in infix form: " ;
	cin.getline ( express, MAX ) ;

	obj.setexpr ( express ) ;
	obj.convert( ) ;

	cout << "\nThe postfix expression is: " ;
	obj.show( ) ;
	return 0;
}
