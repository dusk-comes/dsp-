#include "signal.h"
#include "wave.h"
#include <iostream>
#include <cstdlib>

int main()
{
    double freq = 40;
    double duration = 0.1;
    SawTooth signal(freq, 2, 3.14);
    Wave wave = signal.make_wave(duration);
    wave.plot("trg_n.gpi");
    return 0;
}
