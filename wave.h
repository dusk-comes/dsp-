#pragma once

#include <vector>

class Wave
{
    public:
        Wave() = default;

        Wave(std::vector<double> &time_span, std::vector<double> &amp_span);

    private:
        std::vector<double> _time_span;

        std::vector<double> _amp_span;
};
