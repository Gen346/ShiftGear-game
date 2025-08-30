#include "Car.h"
#include <iostream>
#include <Windows.h>


int main()
{
	Car myCar;

	bool isAccelerating = 0;
	bool isClutch = 0;
	bool isShiftUp = 0;
	bool isShiftDown = 0;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP) && 0x80000)
		{
			isAccelerating = 1;
			myCar.Update(isAccelerating, isClutch, isShiftUp, isShiftDown);
		}
		if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000))
		{
			isClutch = 1;
			isShiftUp = 1;

			myCar.Update(isAccelerating, isClutch, isShiftUp, isShiftDown);
		}
		if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			isClutch = 1;
			isShiftDown = 1;

			myCar.Update(isAccelerating, isClutch, isShiftUp, isShiftDown);
		}

		isAccelerating = 0;
		isClutch = 0;
		isShiftUp = 0;
		isShiftDown = 0;
		
	}
}
//     In development:
		//1. Add timer method
		//2. Add score method
		//3. If 250 km/h reached - end game. Set score in time and RPM
		//4. Sort scores, input names for save
        //5. Online scores
        //6. Lan game