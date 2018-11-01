#pragma once

#include "base.h"

#include <cmath>

// Describes a base class  for a clock hand for the task
class ClockHand
{
public:
	//virtual ~ClockHand()=default;

	int getAzimuth()const{return azimuth;}
	//virtual setTime(time_t) = 0;
protected:
	void setAzimuth(int v){azimuth = v;};
private:
	int azimuth = 0; // angle of the hand with upper posiiton
};

// returns positive angle 0 .. 180
int angle(const ClockHand& ch1, const ClockHand& ch2)
{
	auto angle = std::abs(ch1.getAzimuth() - ch2.getAzimuth());
	if (angle > numDegrees/2) {
		angle = 360 - angle;
	}
	return angle;
}
