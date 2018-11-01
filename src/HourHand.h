#pragma once

#include "ClockHand.h"

class HourHand : public ClockHand
{
public:
	HourHand(time_t t) {setClockTime(t);}

	void setClockTime(time_t t) //override
	{
		setAzimuth(t%(12*60*60)*numDegrees/(12*60*60));
	}
};
