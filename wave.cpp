#include "wave.h"

Wave::Wave(std::vector<double> &time_span, std::vector<double> &amp_span)
{
    _time_span = std::move(time_span);
    _amp_span = std::move(amp_span);
}
