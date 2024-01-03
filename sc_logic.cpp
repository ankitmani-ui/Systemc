#include "systemc.h"

int sc_main(int argc, char* argv[])
{
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );

	sc_logic read_en;
	sc_logic pad;
	sc_logic enable;
	sc_bit no_x_z;
	pad = 'z';
	cout<<"Value of pad : "<<pad <<endl;
	enable = 0;
	cout<<"Value of enable : "<<enable <<endl;
	read_en == ~enable;
	cout<<"Value of read_en : "<<read_en <<endl;
	if (pad == '1')
	{
		cout<<"Pad is 1 "<< endl;
	}
	else 
	{
		cout<<"Pad is not 1 "<< endl;
	}
	no_x_z = enable;
	cout<<"Value of no_x_z : "<<no_x_z <<endl;
	no_x_z = pad;
        cout<<"Value of no_x_z : "<<no_x_z <<endl;
        pad =sc_logic ('x');
	cout<<"Value of pad : " <<pad <<endl;
	return 1;
}
