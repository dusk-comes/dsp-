#include "signal.h"
#include "wave.h"
#include <iostream>
#include <cstdlib>

int main()
{
    double freq = 40;
    double duration = 0.1;
    SawTooth signal(freq);
    Wave wave = signal.make_wave(duration);
    wave.plot("trg.gpi");
    return 0;
}
