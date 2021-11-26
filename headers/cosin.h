#include "signal.h"

class CoSin : public Signal
{
    public:
       CoSin() = delete;

       using Func = std::function<double(double)>;

       CoSin(Func func, double freq, double amp=1, double phase=0, double samplerate=11025);

    protected:
       void compute_signal(std::vector<double> &buffer) override;

    private:
       Func _func;
       double _angel;
       double _delta;
};
