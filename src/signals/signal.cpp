#include "signal.h"

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

Wave Signal::make_wave(double duration)
{
    size_t samples = duration * Signal::samplerate();
    std::vector<double> buffer(samples);
    compute_signal(buffer);
    return Wave(buffer);
}
