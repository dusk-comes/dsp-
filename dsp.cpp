#include "sin.h"
#include "wave.h"
#include "player.h"
#include "alias.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

int main()
{
    double freq = 40;
    Sin signal(freq, 2, 3.14);
    seconds time{0.06};
    Wave wave = signal.make_wave(time);
    wave.plot("sin.gpi");

    Player player(wave);
    player.init();
    return 0;
}
