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

SinSignal::SinSignal(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _angel{0}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

Wave SinSignal::make_wave(double duration)
{
    int samples = duration * Signal::samplerate();

    std::vector<double> amps(samples);
    std::for_each(std::begin(amps), std::end(amps), [this] (auto &sample) {
            sample = Signal::amp() * std::sin(_angel + Signal::phase());
            _angel += _delta;});

    return Wave(amps, Signal::samplerate());
}

SquareSignal::SquareSignal(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _angel{0}
{
    _delta = 2 * M_PI * Signal::freq() / Signal::samplerate();
}

Wave SquareSignal::make_wave(double duration)
{
    double half_period = 1 / (2 * Signal::freq());

    int samples = duration * Signal::samplerate();
    std::vector<double> amps(samples);
    for(auto it = std::begin(amps); it != std::end(amps); ++it)
    {
        *it = std::signbit(std::sin(_angel + Signal::phase())) ? Signal::amp() : -Signal::amp();
        _angel += _delta;
    }

    return Wave(amps, Signal::samplerate());
}
   

