#pragma once

#include <vector>
#include <utility>

class Wave
{
    public:
        Wave() = default;

        Wave(std::vector<double> amps);

    private:
        std::vector<double> _amps;
};
