/*****************************************************************************************
Filename : AudioFrame.cpp
Version : 1.0
Author : Rutvik Patel
Assignment Number : Assignment 3 - Animation in C++ with Inheritance
Course name-number : C++ Programming - CST8219
Source file : Animation.h, AnimationManager.h, AudioFrame.h, Frame.h, VideoFrame.h, Animation.cpp,
AnimationManager.cpp, Assignment3.cpp, AudioFrame.cpp, Frame.cpp, VideoFrame.cpp
Purpose : File contains overloaded operator method to display Audio Frame data and CalculateFrameResource method.
*****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*****************************************************************************************
Function Name  : CalculateFrameResource
Purpose		   : Prints framename and file size for audio frame
Function In Parameters : none
Function Out Parameters : none
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void AudioFrame::CalculateFrameResource() {
	cout << (*this) << endl;
	cout << "MP3 Lossy Compression" << endl;
	cout << "-------------------------------------------------------- -\n" << endl;
	cout << "bitrate(kbits / s) :     ";
	for (int i = 0; i < RATES; i++)
		cout << " | " << BITRATE[i] << " ";
	cout << endl;
	cout << "-------------------------------------------------------- -" << endl;
	cout << "file size(MB) :         " ;
	for (int i = 0; i < RATES; i++)
		cout << " | " << ((Frame::size) / COMPRESSION_RATIO[i]) << " ";
	cout << endl;
	cout << "-------------------------------------------------------- -" << endl;
}

/*****************************************************************************************
Function Name  : Operator overloading <<
Purpose		   : Prints framename and duration
Function In Parameters : ostream object and AudioFrame object
Function Out Parameters : returns ostream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
std::ostream& operator<<(std::ostream& output, AudioFrame& audioFrame) {
	output << "AudioFrame: " << static_cast<Frame&>(audioFrame) << endl;
	return output;
}