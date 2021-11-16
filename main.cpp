#include "signal.h"
#include "wave.h"

int main()
{
    SinSignal sig(40, 1, 0, 10000);
    Wave w = sig.make_wave(0.1);
    w.plot("sin.gpi");
    return 0;
}
