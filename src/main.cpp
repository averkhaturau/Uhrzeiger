#include "ClockHand.h"
#include <iostream>
#include <iomanip>
#include <assert.h>

int main()
{

	assert(hourHand.getAzimuth(6*60*60)*2 == numDegrees);
	assert(minuteHand.getAzimuth(30*60)*2 == numDegrees);
	assert(secondHand.getAzimuth(30)*2 == numDegrees);

	for (time_t t = 0; t <= 12*60*60; ++t){

		auto angle1 = angle(hourHand, minuteHand, t);
		auto angle2 = angle(minuteHand, secondHand, t);
		auto angle3 = angle(hourHand, secondHand, t);

		if (angle1 == angle2 && angle2 == angle3)
			std::cout << "angle == " << angle1 <<"," <<angle2<<","<<angle3 << " at time "
				<< std::setfill('0') << std::setw(2) << t/60/60 << ":" << std::setfill('0') << std::setw(2) << (t%(60*60))/60 << ":" <<  std::setfill('0') << std::setw(2) << t%60 << std::endl;
	}
}
