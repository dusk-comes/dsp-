#include "signal.h"

class Triangle : public Signal
{
    public:
        Triangle() = delete;

        Triangle(double freq, double amp=1, double phase=0, double samplerate=11025);

    protected:
       void compute_signal(std::vector<double> &buffer) override;

    private:
       double _timeshift;
       double _cycles_per_sample;
};
