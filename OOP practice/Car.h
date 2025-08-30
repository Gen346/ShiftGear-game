#ifndef CAR_H
#define CAR_H

class Car
{
public:
	Car();
	~Car();

private:
	float timer = 0;

	float m_Acceleration = 0;
	float m_Speed = 0;
	int m_RpmAcceleration = 0;
	int m_Rpm = 0;
	int m_Gear = 1;

	static constexpr int gearRation[6] = { 56, 47, 36, 29, 28, 26 };
	static constexpr float speedRation[6] = { 0.5f, 0.6f, 0.7f, 0.8f, 0.6f, 0.4f };


public:
	void Move(bool isAccelerating);
	void ShiftGear(bool isClutch, bool isShiftUp, bool isShiftDown);
	void StartTimer();

	void CalculateSpeed();
	void CalculateRPM();

	void Update(bool isAccelerating, bool isClutch, bool isShiftUp, bool isShiftDown);
};

#endif // !CAR_H

