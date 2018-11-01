#pragma once

#include "ClockHand.h"

class MinuteHand : public ClockHand
{
public:
	MinuteHand(time_t t) {setClockTime(t);}

	void setClockTime(time_t t) //override
	{
		setAzimuth(t%(60*60)*numDegrees/(60*60));
	}
};
