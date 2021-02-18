#pragma once
#include <Xinput.h>

#define KEY_G 0x31
#define KEY_R 0x32
#define KEY_Y 0x33
#define KEY_B 0x34
#define KEY_O 0x35

#define DELAY_MS 8

typedef enum eFrets
{
	NONE = 0,

	G = -0x6B6B,
	R = -0x3333,
	Y = 0x1A1A,
	B = 0x4949,
	O = 0x7F7F,

	GR = -0x5050,
	GY = 0x1919,
	GB = 0x4747,
	GO = 0x7B7B,

	RY = -0x1A1A,
	RB = 0x4848,
	RO = 0x7D7D,

	YB = 0x2F2F,
	YO = 0x7E7E,

	BO = 0x6666,

	GRY = -0x1B1B,
	GRB = 0x4646,
	GRO = 0x7979,

	GYB = 0x2D2D,
	GYO = 0x7A7A,

	GBO = 0x6262,

	RYB = 0x2E2E,
	RYO = 0x7C7C,

	RBO = 0x6464,

	GRYB = 0x2C2C,
	GRYO = 0x7878,
	GRBO = 0x6060,
	GYBO = 0x6161,
	RYBO = 0x6363,

	GRYBO = 0x5F5F
} tdeFrets;

typedef struct stInputs
{
	INPUT g;
	INPUT r;
	INPUT y;
	INPUT b;
	INPUT o;
} tdstInputs;
