#include "signal.h"

class Square : public Signal
{
    public:
        Square() = delete;

        Square(double freq, double amp=1, double phase=0, double samplerate=11025);

    protected:
       void compute_signal(std::vector<frame> &buffer) override;

    private:
       double _angel;
       double _delta;
};
