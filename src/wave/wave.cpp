#include "wave.h"
#include <fstream>
#include <iostream>
#include <iomanip>

Wave::Wave(std::vector<double> &amps, double samplerate) :
    _samplerate{samplerate}
{
    _amps = std::move(amps);
}

void Wave::plot(const std::string &filename)
{
    std::ofstream file{filename};
    if (file.is_open())
    {
        file << std::setprecision(25);
        size_t samples = _amps.size();
        for(size_t i = 0; i < samples; ++i)
        {
            double timestamp = i / _samplerate;
            file << timestamp << ' ' << _amps[i] << '\n';
        }
    }
    else
    {
        std::cout << "Cannot write the file!" << std::endl;
    }
}

double Wave::samplerate() const
{
    return _samplerate;
}

p_amps Wave::wave() const
{
    return _amps;
}
