#include "cosin.h"
#include <cmath>

CoSin::CoSin(Func func, double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _func{func},
    _angel{phase}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

void CoSin::compute_signal(std::vector<double> &buffer)
{
    for (double &sample : buffer)
    {
        sample = Signal::amp() * _func(_angel);
        _angel += _delta;
    }
}
