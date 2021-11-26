#include "sawtooth.h"
#include <cmath>

SawTooth::SawTooth(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _timeshift{phase / (2.0 * M_PI)}
{
    _cycles_per_sample = Signal::freq() / Signal::samplerate();
}

void SawTooth::compute_signal(std::vector<double> &buffer)
{
    for (double &sample : buffer)
    {
        sample = Signal::amp() * std::fmod(_timeshift, 1);
        _timeshift += _cycles_per_sample;
    }
}
