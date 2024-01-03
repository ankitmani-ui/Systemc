#include "systemc.h"
 int sc_main (int argc, char* argv[])
{
	sc_bit x;
	sc_logic y,z;
	x='1';
	y='1';
	z='x';
	if (x==y)
	{
		cout<<"x=y"<<endl;
	}
	else
	{
		x=y;
	        cout<<"x!=y"<<endl;
		cout<<"New Value of x : "<<x<<endl;
	}
	if (y!=z)
	{
		y=z;
		cout<<"y!=z"<<endl;
		cout<<"New Value of y : "<<y<<endl;
	}
	if (y=='x') 
	{
		cout<<"y equal to value 'X'"<<endl;
	}
	return 1;
}
