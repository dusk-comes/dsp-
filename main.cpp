#include "signal.h"
#include "wave.h"

int main()
{
    SinSignal sig(1000, 1, 0, 10000);
    Wave w = sig.make_wave(0.001);
    return 0;
}
