#include "triangle.h"
#include <cmath>

Triangle::Triangle(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _timeshift{phase / (2.0 * M_PI)}
{
    _cycles_per_sample = Signal::freq() / Signal::samplerate();
}

void Triangle::compute_signal(std::vector<frame> &buffer)
{
    double halfperiod = 0.5;
    for (frame &sample : buffer)
    {
        double value = std::fmod(_timeshift, 1);
        value = (value <= halfperiod) ? value : 1 - value;
        double normolized = 2 * Signal::amp() * value;
        sample = normolized;
        _timeshift += _cycles_per_sample;
    }
}
