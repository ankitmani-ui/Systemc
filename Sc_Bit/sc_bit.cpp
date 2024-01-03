#include "systemc.h"

int sc_main (int argc, char* arvg[])
{
	sc_bit enable;
	sc_bit read_en;
	enable =1;
	cout<<"Value of enable : "<< enable << endl;
	read_en =enable;
	cout<<"Value of read_en : "<<read_en<<endl;
	return 1;
}
