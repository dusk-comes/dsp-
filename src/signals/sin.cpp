#include "sin.h"
#include <cmath>

Sin::Sin(double freq, double amp, double phase, double samplerate) :
    CoSin((double(*)(double))&std::sin, freq, amp, phase, samplerate)
{
}
