#pragma once

#include <cstddef>
#include "wave.h"
#include <memory>
#include <vector>

class Player
{
    public:
        Player() = delete;

        Player(const Wave &wave);

    private:
        size_t _position;
        const double _samplerate;
        const std::vector<double> &_data;
};
