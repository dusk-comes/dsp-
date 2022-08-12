#include "signal.h"

Signal::Signal(double freq, double amp, double phase, double samplerate) :
    _freq{freq},
    _amp{amp},
    _phase{phase},
    _samplerate{samplerate}
{
}

double Signal::freq() const
{
    return _freq;
}

double Signal::amp() const
{
    return _amp;
}

double Signal::phase() const
{
    return _phase;
}

double Signal::samplerate() const
{
    return _samplerate;
}

Wave Signal::make_wave(seconds time)
{
    size_t samples = time.count() * Signal::samplerate();
    std::vector<frame> buffer(samples);
    compute_signal(buffer);
    return Wave(buffer);
}
