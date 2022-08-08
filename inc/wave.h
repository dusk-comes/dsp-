#pragma once

#include <vector>
#include <string>
#include <utility>
#include <memory>

using frame = float;

class Wave
{
    public:
        Wave() = default;

        Wave(std::vector<frame> &amps, double samplerate=11025);

        void plot(const std::string &filename);

        double samplerate() const;

        const std::vector<frame> &wave() const;

    private:
        double _samplerate;
        std::vector<frame> _amps;
};
