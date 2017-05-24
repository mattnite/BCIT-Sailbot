// sail object

#ifndef SAIL_H_
#define SAIL_H_

class aileron
{
    float Tswing;			// Time from +ve to -ve
    float pos;				// Current position from 1 to -1
public:

    //ctor
    aileron(float period);

    // get position
    float Pos();

    // update new position
    void update(float input, float interval);
}

class sail
{
    float theta;			// Absolute angle of sail
    float I;				// moment of intertia

}

#endif
