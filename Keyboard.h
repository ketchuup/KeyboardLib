#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <cstdio>
#include <ctime>
#include <termios.h>
#include <sys/types.h>

static struct termios defaultSettings;      // Input mode settings
static struct termios pressModeSettings;    // Press mode settings
static struct timeval selectWorkTime;
static fd_set readFileDescriptorSet;

void initialize();
void setInputMode();
void setPressMode();
int getPressedKey();

#endif