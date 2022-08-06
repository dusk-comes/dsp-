#include "sin.h"
#include "wave.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    double freq = 40;
    double duration = 0.06;
    Sin signal(freq, 2, 3.14);
    Wave wave = signal.make_wave(duration);
    wave.plot("trg.gpi");

    Player player(wave);
    player.init();
    return 0;
}
