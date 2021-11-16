#include "wave.h"

Wave::Wave(std::vector<double> amps)
{
    _amps= std::move(amps);
}
