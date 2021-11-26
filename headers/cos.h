#include "cosin.h"

class Cos : public CoSin
{
    public:
        Cos() = delete;

        Cos(double freq, double amp=1, double phase=0, double samplerate=11025);
};
