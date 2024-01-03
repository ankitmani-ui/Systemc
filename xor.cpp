#include <systemc.h>

SC_MODULE(NANDGate) {
    sc_in<bool> in1;
    sc_in<bool> in2;
    sc_out<bool> out;

    SC_CTOR(NANDGate) {
        SC_METHOD(operation);
        sensitive << in1 << in2;
    }

    void operation() {
        out.write(!(in1.read() && in2.read()));
    }
};

SC_MODULE(XORGate) {
    sc_in<bool> in1;
    sc_in<bool> in2;
    sc_out<bool> out;

    sc_signal<bool> s1, s2, s3, s4, s5;

    NANDGate nand1{"nand1"};
    NANDGate nand2{"nand2"};
    NANDGate nand3{"nand3"};
    NANDGate nand4{"nand4"};
    NANDGate nand5{"nand5"};

    SC_CTOR(XORGate) : nand1("nand1"), nand2("nand2"), nand3("nand3"), nand4("nand4"), nand5("nand5") {
        // Connect NAND gates
        nand1.in1(in1);
        nand1.in2(in1);
        nand1.out(s1);

        nand2.in1(in2);
        nand2.in2(in2);
        nand2.out(s2);

        nand3.in1(in1);
        nand3.in2(s2);
        nand3.out(s3);

        nand4.in1(s1);
        nand4.in2(in2);
        nand4.out(s4);

        nand5.in1(s3);
        nand5.in2(s4);
        nand5.out(out);
    }
};

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> signal_in1, signal_in2, signal_out;

    XORGate xor_gate("xor_gate");
    xor_gate.in1(signal_in1);
    xor_gate.in2(signal_in2);
    xor_gate.out(signal_out);

    // Test the XOR gate
    cout << "0 XOR 0 = " << (signal_in1 = false, signal_in2 = false, sc_start(), signal_out.read()) << endl;
    cout << "0 XOR 1 = " << (signal_in1 = false, signal_in2 = true, sc_start(), signal_out.read()) << endl;
    cout << "1 XOR 0 = " << (signal_in1 = true, signal_in2 = false, sc_start(), signal_out.read()) << endl;
    cout << "1 XOR 1 = " << (signal_in1 = true, signal_in2 = true, sc_start(), signal_out.read()) << endl;

    return 0;
}

