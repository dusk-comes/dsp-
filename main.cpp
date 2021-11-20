#include "signal.h"
#include "wave.h"

int main()
{
    double freq = 40;
    Sin sin_sig(freq, 5, 3.14/2);
    Wave sin_wave = sin_sig.make_wave(0.1);
    sin_wave.plot("sin.gpi");
    return 0;
}
