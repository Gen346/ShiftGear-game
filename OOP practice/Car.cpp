#include "Car.h"
#include <iostream>
#include <Windows.h>

Car::Car() {} 

Car::~Car() {}


void Car::Update(bool isAccelerating, bool isClutch, bool isShiftUp, bool isShiftDown)
{
	Move(isAccelerating);
	ShiftGear(isClutch, isShiftUp, isShiftDown);
}

void Car::Move(bool isAccelerating)
{
	if (isAccelerating)
	{
		system("cls");
		CalculateSpeed();
		CalculateRPM();

		m_Speed += m_Acceleration;
		m_Rpm += m_RpmAcceleration;

		std::cout << "Speed: " << (int)m_Speed
			<< " km/h  |  RPM: " << m_Rpm
			<< "  |  Gear: " << m_Gear
			<< std::endl;
		Sleep(50);
	}

	else
	{
		m_Speed -= 0.5f;
		m_Rpm -= 1;
		Sleep(50);
	}
}

void Car::ShiftGear(bool isClutch, bool isUpShift, bool isShiftDown)
{
	if (isClutch && isUpShift && (m_Rpm > 2000) && m_Gear < 6)
	{
		m_Gear++;
		m_Rpm -= 2000;
	}

	if (isClutch && isShiftDown && (m_Rpm <= 7000) && m_Gear > 1)
	{
		m_Gear--;
		m_Rpm += 2000;
	}
}

void Car::StartTimer()
{
	timer += 0.01f;
	Sleep(1);
}

void Car::CalculateSpeed()
{
	if (m_Speed > 291)
	{
		m_Acceleration = 0;
	}
	else
	{
		m_Acceleration = speedRation[m_Gear - 1];
	}
}

void Car::CalculateRPM()
{
	if (m_Speed > 291)
	{
		m_RpmAcceleration = 0;
	}
	else
	{
		m_RpmAcceleration = gearRation[m_Gear - 1];
	}
}