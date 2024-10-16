#include"Memory.h"
#include<iostream>
#include<Windows.h>
#include<thread>

using namespace std;

//space bar : 0x20

//offsets
uint32_t Standing = 65665;
uint32_t Crouching = 65667;
uint32_t Plus_Jump = 65537;
uint32_t Minus_Jump = 256;

uint32_t dwLocalPlayerPawn = 0x1825138;//old :0x1823128
uint32_t dwForceJump = 0x181E140; //old : 0x181C130
uint32_t m_fFlags = 0x3EC; // old : 0x3EC

void bhop()
{
	//mouse wheel down
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_WHEEL;
	input.mi.mouseData = -WHEEL_DELTA;

	//mouse wheel up
	INPUT inputup;
	inputup.type = INPUT_MOUSE;
	inputup.mi.dwFlags = MOUSEEVENTF_WHEEL;
	inputup.mi.mouseData = WHEEL_DELTA;

	Memory mem("cs2.exe");
	
	uintptr_t client = mem.GetModuleAddress("client.dll"); //getting module address
	uintptr_t Forcejump = client + dwForceJump; //jump address

	//main hack loop
	while (true)
	{
		uintptr_t Local_Player = mem.Read<uintptr_t>(client + dwLocalPlayerPawn); //I dont know why the cast is important

		uint32_t fFlag = mem.Read<uint32_t>(Local_Player + m_fFlags); //change to uint32_t if doesn't work

		if (GetAsyncKeyState(0x20) & 0x8000)
		{
			if (fFlag == Standing || fFlag == Crouching)
			{
				cout << "On the grond"<<endl;
				SendInput(1, &input, sizeof(INPUT));
				//mem.Write<uintptr_t>(Forcejump, Plus_Jump);
				this_thread::sleep_for(chrono::milliseconds(1)); //sleeping to improve performance
			}
			else
			{
				SendInput(1, &inputup, sizeof(INPUT));
				//mem.Write<uintptr_t>(Forcejump, Minus_Jump);
				this_thread::sleep_for(chrono::milliseconds(1)); //sleeping to improve performance
			}
		}
		else
		{
			this_thread::sleep_for(chrono::milliseconds(1)); //sleeping to improve performance
		}
	}
}

int main(void)
{
	bhop();

	return 0;
}