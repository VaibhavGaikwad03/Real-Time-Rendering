#pragma once

#include <freeglut/GL/freeglut.h>
#include <math.h>
#include <Windows.h>

// Symbolic Constants
#define WIDTH 600
#define HEIGHT 400

#define RECORDING_FRAME_TIMER 101
#define RECORDING_FRAME_TIMER_MILLISECONDS 5

#define RECORDING_INDICATOR_TIMER 102
#define RECORDING_INDICATOR_TIMER_MILLISECONDS 1000

#define LETTER_DISPLAY_TIMER 103
#define LETTER_DISPLAY_TIMER_MILLISECONDS 10

// Function Declaration
// Timer Functions
void timerRecordingIndicator(int);
void timerLetterDisplay(int);
void timerRecordingFrame(int);

void RecordingFrame(float, float);
void LetterHider(float);
void LetterS(void);
void LetterH(void);
void LetterA(void);
void LetterD(void);
void LetterE(void);
void LetterR(void);
void LetterSL(void);
void RecordingIndicator(void);