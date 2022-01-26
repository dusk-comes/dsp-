#include "asoundlib.h"

#include "player.h"
#include <vector>
Player::Player(const Wave &wave) :
    _position{0},
    _buffer_size{512},
    _samplerate(wave.samplerate()),
    _data(wave.wave())
{
}

void init()
{
}
