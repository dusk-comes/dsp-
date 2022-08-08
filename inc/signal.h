#pragma once

#include "alias.h"
#include "wave.h"

#include <functional>
#include <vector>

class Signal
{
    public:
        Signal() = delete;

        Signal(double freq, double amp=1, double phase=0, double samplerate=11025);

        double freq() const;

        double amp() const;

        double phase() const;

        double samplerate() const;

        Wave make_wave(double duration);

    protected:
        virtual void compute_signal(std::vector<frame> &buffer) = 0;

    private:
        double _freq;
        double _amp;
        double _phase;
        double _samplerate;
};
