#include "signal.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

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

void Square::compute_signal(std::vector<double> &buffer)
{
    for (double &sample : buffer)
    {
        double current_postion = std::fmod(_angel, 2.0 * M_PI);
        sample = (current_postion <= M_PI) ? Signal::amp() : -Signal::amp();
        _angel += _delta;
    }
}

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

Triangle::Triangle(double freq, double amp, double phase, double samplerate) :
    Signal(freq, amp, phase, samplerate),
    _timeshift{phase / (2.0 * M_PI)}
{
    _cycles_per_sample = Signal::freq() / Signal::samplerate();
}

void Triangle::compute_signal(std::vector<double> &buffer)
{
    double halfperiod = 0.5;
    for (double &sample : buffer)
    {
        double value = std::fmod(_timeshift, 1);
        value = (value <= halfperiod) ? value : 1 - value;
        double normolized = 2 * Signal::amp() * value;
        sample = normolized;
        _timeshift += _cycles_per_sample;
    }
}
