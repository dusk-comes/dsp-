#include "signal.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>

Signal::Signal(double freq, double amp, double phase, double samplerate) :
    _freq{freq},
    _amp{amp},
    _phase{phase},
    _samplerate{samplerate}
{
}

double Signal::freq()
{
    return _freq;
}

double Signal::amp()
{
    return _amp;
}

double Signal::phase()
{
    return _phase;
}

double Signal::samplerate()
{
    return _samplerate;
}

CoSin::CoSin(Func func, double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _func{func},
    _angel{phase}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

Wave CoSin::make_wave(double duration)
{
    int samples = duration * Signal::samplerate();

    std::vector<double> amps(samples);
    for (double &sample : amps)
    {
        sample = Signal::amp() * _func(_angel);
        _angel += _delta;
    }

    return Wave(amps);
}

Sin::Sin(double freq, double amp, double phase, double samplerate) :
    CoSin((double(*)(double))&std::sin, freq, amp, phase, samplerate)
{
}

Cos::Cos(double freq, double amp, double phase, double samplerate) :
    CoSin((double(*)(double))&std::cos, freq, amp, phase, samplerate)
{
}

Square::Square(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _angel{phase}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

Wave Square::make_wave(double duration)
{
    int samples = duration * Signal::samplerate();

    std::vector<double> amps(samples);

    for (double &sample : amps)
    {
        double current_postion = std::fmod(_angel, 2.0 * M_PI);

        if (current_postion <= M_PI) sample = Signal::amp();
        else sample = -Signal::amp();

        _angel += _delta;
    }

    return Wave(amps);
}
