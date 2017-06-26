#ifndef SINE_H_INCLUDED
#define SINE_H_INCLUDED


class Sine {
public:
    Sine() {}

    void updateAngleDelta() {
        angleDelta = sampleRate * 2.0 * 3.14;
    }

    double getAngleDelta() {
        return angleDelta;
    }

private:
    double sampleRate = 44000;
    double angle = 0;
    double angleDelta = 0;
};


#endif  // SINE_H_INCLUDED
