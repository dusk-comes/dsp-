#include "cosin.h"

class Sin : public CoSin
{
    public:
        Sin() = delete;

        Sin(double freq, double amp=1, double phase=0, double samplerate=11025);
};
