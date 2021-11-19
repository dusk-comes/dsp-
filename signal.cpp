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

CoSin::CoSin(std::function<double(double)> func, double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _angel{phase}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
    _func = [func](double arg) {return func(arg);};
}

Wave CoSin::make_wave(double duration)
{
    int samples = duration * Signal::samplerate();

    std::vector<double> amps(samples);
    std::for_each(amps.begin(), amps.end(), [this](double &sample) {
            sample = Signal::amp() * _func(_angel);
            _angel += _delta;});
}

Sin::Sin(double freq, double amp, double phase, double samplerate) :
    CoSin(std::sin, freq, amp, phase, samplerate)
{
}
