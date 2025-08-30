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