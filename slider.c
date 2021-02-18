#include <Windows.h>
#include <Xinput.h>
#include <stdlib.h>
#include <stdio.h>

#include "slider.h"

#define PRESS(stInputs) ((stInputs).ki.dwFlags = 0)
#define RELEASE(stInputs) ((stInputs).ki.dwFlags = KEYEVENTF_KEYUP)

void fn_vInitInputs( tdstInputs *p_stInputs )
{
	INPUT stInput = { 0 };
	stInput.type = INPUT_KEYBOARD;

	p_stInputs->g = p_stInputs->r = p_stInputs->y = p_stInputs->b = p_stInputs->o = stInput;

	p_stInputs->g.ki.wVk = KEY_G;
	p_stInputs->r.ki.wVk = KEY_R;
	p_stInputs->y.ki.wVk = KEY_Y;
	p_stInputs->b.ki.wVk = KEY_B;
	p_stInputs->o.ki.wVk = KEY_O;
}

void fn_vSendInputs( tdstInputs *p_stInputs )
{
	SendInput(5, (LPINPUT)p_stInputs, sizeof(INPUT));
}

int main()
{
	XINPUT_STATE xState = { 0 };
	tdstInputs stInputs;
	tdeFrets prevSlider = NONE;

	fn_vInitInputs(&stInputs);
	
	puts("Slider bar mapped to keyboard keys 1-5. Press Ctrl-C to exit.");

	while ( TRUE )
	{
		if ( XInputGetState(0, &xState) != ERROR_SUCCESS )
			continue;

		tdeFrets slider = xState.Gamepad.sThumbLX;

		RELEASE(stInputs.g);
		RELEASE(stInputs.r);
		RELEASE(stInputs.y);
		RELEASE(stInputs.b);
		RELEASE(stInputs.o);

		switch ( slider )
		{
		case NONE:
			break;

		case G:
			PRESS(stInputs.g);
			break;
		case R:
			PRESS(stInputs.r);
			break;
		case Y:
			PRESS(stInputs.y);
			break;
		case B:
			PRESS(stInputs.b);
			break;
		case O:
			PRESS(stInputs.o);
			break;

		case GR:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			break;
		case GY:
			PRESS(stInputs.g);
			PRESS(stInputs.y);
			break;
		case GB:
			PRESS(stInputs.g);
			PRESS(stInputs.b);
			break;
		case GO:
			PRESS(stInputs.g);
			PRESS(stInputs.o);
			break;

		case RY:
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			break;
		case RB:
			PRESS(stInputs.r);
			PRESS(stInputs.b);
			break;
		case RO:
			PRESS(stInputs.r);
			PRESS(stInputs.o);
			break;

		case YB:
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			break;
		case YO:
			PRESS(stInputs.y);
			PRESS(stInputs.o);
			break;

		case BO:
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;

		case GRY:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			break;
		case GRB:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.b);
			break;
		case GRO:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.o);
			break;

		case GYB:
			PRESS(stInputs.g);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			break;
		case GYO:
			PRESS(stInputs.g);
			PRESS(stInputs.y);
			PRESS(stInputs.o);
			break;

		case GBO:
			PRESS(stInputs.g);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;

		case RYB:
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			break;
		case RYO:
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.o);
			break;

		case RBO:
			PRESS(stInputs.r);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;

		case GRYB:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			break;
		case GRYO:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.o);
			break;
		case GRBO:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;
		case GYBO:
			PRESS(stInputs.g);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;
		case RYBO:
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;

		case GRYBO:
			PRESS(stInputs.g);
			PRESS(stInputs.r);
			PRESS(stInputs.y);
			PRESS(stInputs.b);
			PRESS(stInputs.o);
			break;
		}

		if ( slider != prevSlider )
		{
			fn_vSendInputs(&stInputs);
			prevSlider = slider;
		}

		Sleep(DELAY_MS);
	}
}
