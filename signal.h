#pragma once

#include <functional>

#include "wave.h"

class Signal
{
    public:
        Signal() = delete;

        Signal(double freq, double amp=1, double phase=0, double samplerate=11025);

        double freq();

        double amp();

        double phase();

        double samplerate();

        virtual Wave make_wave(double duration) = 0;

    private:
        double _freq;
        double _amp;
        double _phase;
        double _samplerate;
};

class CoSin : public Signal
{
    public:
       CoSin() = delete;

       CoSin(std::function<double(double)> func, double freq, double amp=1, double phase=0, double samplerate=11025);

       Wave make_wave(double duration) override;

    private:
       double _angel;
       double _delta;
       std::function<double(double)> _func;
};

class Sin : public CoSin
{
    public:
        Sin() = delete;

        Sin(double freq, double amp=1, double phase=0, double samplerate=11025);
};
