#include "Keyboard.h"

// 0 in tcgetattr and tcsetattr calls is a stdin descriptor
// TCSANOW means that changes start working immediately

void initialize()
{
	tcgetattr(0, &defaultSettings);
	pressModeSettings = defaultSettings;

	// Guide: https://habr.com/ru/post/124789/
	// Documentation: https://www.opennet.ru/man.shtml?topic=termios&category=3&russian=0

	pressModeSettings.c_lflag &= ~(ICANON | ECHO);    // Disable canonical mode and displaying entered characters
	pressModeSettings.c_cc[VTIME] = 0;                // Wait time in deciseconds for non-canonical input
	pressModeSettings.c_cc[VMIN] = 1;                 // Minimal number of characters for non-canonical input

	selectWorkTime.tv_sec = 0;
	selectWorkTime.tv_usec = 0;
}

void setInputMode()
{
	tcsetattr(0, TCSANOW, &defaultSettings);
}

void setPressMode()
{
	tcsetattr(0, TCSANOW, &pressModeSettings);
}

int getPressedKey()
{
	FD_ZERO(&readFileDescriptorSet);
	FD_SET(0, &readFileDescriptorSet);

	// select() parameters: number of descriptors, read descriptors, write descriptors, error descriptors, function work time
	int selectReturn = select(1, &readFileDescriptorSet, nullptr, nullptr, &selectWorkTime);

	if (selectReturn)
	{
		return getchar();
	}

	return 0;
}
