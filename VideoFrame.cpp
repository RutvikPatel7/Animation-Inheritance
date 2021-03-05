/*****************************************************************************************
Filename : VideoFrame.cpp
Version : 1.0
Author : Rutvik Patel
Student's name : Rutvik Patel
Assignment Number : Assignment 3 - Animation in C++ with Inheritance
Course name-number : C++ Programming - CST8219
Source file : Animation.h, AnimationManager.h, AudioFrame.h, Frame.h, VideoFrame.h, Animation.cpp,
AnimationManager.cpp, Assignment3.cpp, AudioFrame.cpp, Frame.cpp, VideoFrame.cpp
Purpose : File contains overloaded operator method to display Video Frame data and CalculateFrameResource method.
*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*****************************************************************************************
Function Name  : CalculateFrameResource
Purpose		   : Prints framename and file size for video frame
Function In Parameters : none
Function Out Parameters : none
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void VideoFrame::CalculateFrameResource() {
	cout << (*this) << endl;
	cout << "Lempel-Ziv-Welch Lossless Compression" << endl;
	cout << "-------------------------------------------------------- -\n" << endl;
	cout << "colours:         ";
	for (int i = 1; i <= BITS; i++)
		cout << " | " << pow(2,i) << "   ";
	cout << endl;
	cout << "-------------------------------------------------------- -" << endl;
	cout << "file size(MB) :  ";
	for (int i = 0; i < BITS; i++)
		cout << " | " << ((Frame::size) / (BITDEPTH_FACTOR[i]*COMPRESSION_RATIO)) << " ";
	cout << endl;
	cout << "-------------------------------------------------------- -" << endl;
}

/*****************************************************************************************
Function Name  : Operator overloading << 
Purpose		   : Prints framename and duration
Function In Parameters : ostream object and VideoFrame object
Function Out Parameters : returns ostream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
ostream& operator<<(ostream& output, VideoFrame& videoFrame) {
	output << "VideoFrame: "<< static_cast<Frame&>(videoFrame) << endl;
	return output;
}