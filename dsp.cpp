#include "triangle.h"
#include "wave.h"
#include <iostream>
#include <cstdlib>

int main()
{
    double freq = 40;
    double duration = 0.06;
    Triangle signal(freq, 2, 3.14);
    Wave wave = signal.make_wave(duration);
    wave.plot("trg.gpi");
    return 0;
}
