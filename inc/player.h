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

        void init();

    private:
        const size_t _buffer_size;
        const double _samplerate;
        const std::vector<frame> &_data;
};
