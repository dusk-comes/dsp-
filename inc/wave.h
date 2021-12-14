#pragma once

#include <vector>
#include <string>
#include <utility>
#include <memory>

using p_amps = std::shared_ptr<std::vector<double>>;

class Wave
{
    public:
        Wave() = default;

        Wave(std::vector<double> &amps, double samplerate=11025);

        void plot(const std::string &filename);

        double samplerate() const;

        p_amps wave() const;

    private:
        double _samplerate;
        std::vector<double> _amps;
};
