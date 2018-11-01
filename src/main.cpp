#include "SecondHand.h"
#include "MinuteHand.h"
#include "HourHand.h"
#include <iostream>
#include <iomanip>

int main()
{
	// for (time_t t = 0; t <= 12*60*60; ++t){
	// 	if (0 == t%(60*60))
	// 		std::cout << " hour azimuth is " << HourHand(t).getAzimuth() << " at " << t/60/60 << ":" << (t%60)/60 << ":" << t%60 << std::endl;
	// }
	// for (time_t t = 0; t <= 60*60; ++t){
	// 	if (0 == t%60)
	// 		std::cout << " minute azimuth is " << MinuteHand(t).getAzimuth() << " at " << t/60/60 << ":" << t%(60*60)/60 << ":" << t%60 << std::endl;
	// }

	for (time_t t = 0; t <= 12*60*60; ++t){

		auto angle1 = angle(HourHand(t), MinuteHand(t));
		auto angle2 = angle(MinuteHand(t), SecondHand(t));
		auto angle3 = angle(HourHand(t), SecondHand(t));

		if (angle1 == angle2 && angle2 == angle3)
			std::cout << "angle == " << angle1 <<"," <<angle2<<","<<angle3 << " at time "
				<< std::setfill('0') << std::setw(2) << t/60/60 << ":" << std::setfill('0') << std::setw(2) << (t%(60*60))/60 << ":" <<  std::setfill('0') << std::setw(2) << t%60 << std::endl;

	}

}