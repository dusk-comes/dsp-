#pragma once

#include <vector>
#include <string>
#include <utility>
#include <memory>

class Wave
{
    public:
        Wave() = default;

        Wave(std::vector<double> &amps, double samplerate=11025);

        void plot(const std::string &filename);

        double samplerate() const;

        std::vector<double> wave() const;

    private:
        double _samplerate;
        std::vector<double> _amps;
};
