#pragma once

#include "ClockHand.h"

class SecondHand : public ClockHand
{
public:
	SecondHand(time_t t){setClockTime(t);}

	void setClockTime(time_t t) //override
	{
		setAzimuth(t%(60)*numDegrees/60);
	}
};
