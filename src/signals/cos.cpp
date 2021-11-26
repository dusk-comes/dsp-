#include "cos.h"
#include <cmath>

Cos::Cos(double freq, double amp, double phase, double samplerate) :
    CoSin((double(*)(double))&std::cos, freq, amp, phase, samplerate)
{
}
