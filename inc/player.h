#pragma once


#include <cstddef>
#include "wave.h"
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
        const std::vector<double> &_data;
};
