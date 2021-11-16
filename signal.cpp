#include "signal.h"
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
    int samples = duration * samplerate();

    std::vector<double> amps(samples);
    std::for_each(std::begin(amps), std::end(amps),
                  [this](auto &sample)
            {
                sample = Signal::amp() * std::sin(_angel + Signal::phase());
                _angel += _delta;
            });

    return Wave(amps, Signal::samplerate());
}

