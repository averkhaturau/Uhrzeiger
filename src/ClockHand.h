#pragma once

#include "base.h"

#include <cmath>
#include <functional>

// Describes a base class  for a clock hand for the task
class ClockHand
{
public:
	ClockHand(std::function<int(time_t)> timeToAzimuth) : timeToAzimuthFn(timeToAzimuth) {}
	int getAzimuth(time_t time)const{return timeToAzimuthFn(time);}
private:
	std::function<int(time_t)> timeToAzimuthFn;
};

// returns positive angle 0 .. 180
int angle(const ClockHand& ch1, const ClockHand& ch2, time_t t)
{
	auto angle = std::abs(ch1.getAzimuth(t) - ch2.getAzimuth(t));
	if (angle > numDegrees/2) {
		angle = 360 - angle;
	}
	return angle;
}


const ClockHand hourHand([](time_t t){return t%(12*60*60)*numDegrees/(12*60*60);});

const ClockHand minuteHand([](time_t t){return t%(60*60)*numDegrees/(60*60);});

const ClockHand secondHand([](time_t t){return t%60*numDegrees/60;});
