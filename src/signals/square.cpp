#include "square.h"
#include <cmath>

Square::Square(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _angel{phase}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

void Square::compute_signal(std::vector<double> &buffer)
{
    for (double &sample : buffer)
    {
        double current_postion = std::fmod(_angel, 2.0 * M_PI);
        sample = (current_postion <= M_PI) ? Signal::amp() : -Signal::amp();
        _angel += _delta;
    }
}
