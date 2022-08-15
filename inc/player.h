#pragma once

#include "alias.h"
#include "wave.h"

#include <cstddef>
#include <memory>
#include <vector>

struct Settings
{
};

class Player
{
    public:
        Player() = delete;

        Player(const Wave &wave);

        void play();

    private:
        std::array<frame, 512> _buffer;
        const double _samplerate;
        const std::vector<frame> &_data;
};
