#include "signal.h"
#include "wave.h"

int main()
{
    double freq = 40;
    Cos sin_sig(freq);
    Wave sin_wave = sin_sig.make_wave(0.03);
    sin_wave.plot("cos.gpi");
    return 0;
}
