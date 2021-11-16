#pragma once

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

    private:
        double _freq;
        double _amp;
        double _phase;
        double _samplerate;
};

class SinSignal : public Signal
{
    public:
        SinSignal() = delete;

        SinSignal(double freq, double amp=1, double phase=0, double samplerate=11025);

        Wave make_wave(double duration);

    private:
        double _angel;
        double _delta;
};
