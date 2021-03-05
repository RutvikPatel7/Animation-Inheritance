/*****************************************************************************************
Filename : Animation.cpp
Version : 1.0
Author : Rutvik Patel
Assignment Number : Assignment 3 - Animation in C++ with Inheritance
Course name-number : C++ Programming - CST8219
Source file : Animation.h, AnimationManager.h, AudioFrame.h, Frame.h, VideoFrame.h, Animation.cpp,
AnimationManager.cpp, Assignment3.cpp, AudioFrame.cpp, Frame.cpp, VideoFrame.cpp
Purpose : File contains constructors, destructors and required methods to create, delete and edit
	Frame.
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
#include <typeinfo>
#include "Animation.h"
#include "AnimationManager.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*****************************************************************************************
Function Name  : Animation Destructor
Purpose		   : Clears the frame.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
Animation::~Animation() {
	frames.clear();
}

/*****************************************************************************************
Function Name  : EditFrame
Purpose		   : Prompts user to enter frame number and updates selected frame.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void Animation::EditFrame() {
	printf("Edit a frame in the Animation\n");
	if (this->frames.empty()) {
		printf("There is no frame to edit.\n");
	}
	else {
		int length = 0;
		for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
			length++;
		}
		printf("There are %d Frame(s) in the list. Please specify the index (<=%d) to edit at :", length, length - 1);
		int userInput = 0;
		cin >> userInput;
		if (userInput < 0 || userInput >= length) {
			cout << "Invalid user input..!" << endl;
			return;
		}

		forward_list<Frame*>::iterator it;
		it = this->frames.begin();
		it = next(it, userInput);
		std::string name;
		double size;

		cout << "The name and size of this Frame are " << endl;
		(*it)->CalculateFrameResource();
		cout << " What do you wish to replace them with?" << endl;
		cout << "Name :";
		cin >> name;
		cout << "Size :";
		cin >> size;
		it = next(this->frames.begin(), userInput - 1);
		if (dynamic_cast<AudioFrame*>(*it) != nullptr) {
			this->frames.erase_after(it);
			this->frames.insert_after(it, new AudioFrame(name, size));
		}
		else {
			this->frames.erase_after(it);
			this->frames.insert_after(it, new AudioFrame(name, size));
		}

	}
}

/*****************************************************************************************
Function Name  : DeleteFrame
Purpose		   : Prompts user to enter frame number and delete selected frame.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void Animation::DeleteFrame() {
	if (this->frames.empty()) {
		printf("There is no frame to delete.\n");
	}
	else {
		printf("Delete a Frame in the Animation\n");
		int length = 0;
		for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
			length++;
		}
		printf("Which Animation do you wish to delete? Please give the index in the range 0 to %d :"
			, length - 1);
		int userInput = 0;
		cin >> userInput;
		if (userInput < 0 || userInput >= length) {
			cout << "Invalid user input..!" << endl;
			return;
		}
		if (userInput == 0) this->frames.pop_front();
		else {
			int index = 1;
			for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
				if (index == userInput) {
					this->frames.erase_after(frame); break;
				}
				index++;
			}
		}
		printf("Frame #%d deleted\n", userInput);
	}
}

/*****************************************************************************************
Function Name  : Overloaded operator >>
Purpose		   : Prompts user to enter frame name and duration and inserts frame in the animation.
Function In Parameters : istream object and Animation object.
Function Out Parameters : istream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
istream& operator>>(std::istream& input, Animation& animation) {
	std::string name;
	double size;
	std::string type;
	cout << "Insert a frame in the Animation" << endl;
	cout << "Please enter the Frame frameName :";
	input >> name;
	cout << "Please enter the Frame size(MB):";
	input >> size;
	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V):";
	input >> type;
	if (type == "A" || type == "a") {
		animation.frames.emplace_front(new AudioFrame(name, size));
	}
	else if (type == "V" || type == "v") {
		animation.frames.emplace_front(new VideoFrame(name, size));
	}
	cout << "Frame " << name << " Frame* added at the front of frames" << endl;
	return input;
}

/*****************************************************************************************
Function Name  : Overloaded operator <<
Purpose		   : Prints Frame detail for the current animation.
Function In Parameters : ostream object and Animation object.
Function Out Parameters : ostream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
ostream& operator<<(std::ostream& output, Animation& animation) {
	output << "\tAnimation name is " << animation.animationName << "\n"
		<< "\tReport the Animation\n";
	if (animation.frames.empty()) {
		output << "\tNo frames in the Animation.\n";
	}
	else {
		int index = 0;
		for (forward_list<Frame*>::iterator frame = animation.frames.begin(); frame != animation.frames.end(); ++frame) {
			output << "Frame# " << index++ << "\n";
			(*frame)->CalculateFrameResource();
		}
	}
	return output;
}