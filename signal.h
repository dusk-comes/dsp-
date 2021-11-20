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

       using Func = std::function<double(double)>;

       CoSin(Func func, double freq, double amp=1, double phase=0, double samplerate=11025);

       Wave make_wave(double duration) override;

    private:
       Func _func;
       double _angel;
       double _delta;
};

class Sin : public CoSin
{
    public:
        Sin() = delete;

        Sin(double freq, double amp=1, double phase=0, double samplerate=11025);
};

class Cos : public CoSin
{
    public:
        Cos() = delete;

        Cos(double freq, double amp=1, double phase=0, double samplerate=11025);
};

class Square : public Signal
{
    public:
        Square() = delete;

        Square(double freq, double amp=1, double phase=0, double samplerate=11025);

        Wave make_wave(double duration);

    private:
       double _angel;
       double _delta;
};
