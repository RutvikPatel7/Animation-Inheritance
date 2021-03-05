//Frame.h
#pragma once

class Frame {
	std::string frameName;
protected:
	double size;
public:
	Frame(std::string name, double sz) :frameName(name), size(sz) {};
	virtual ~Frame() {};
	virtual void CalculateFrameResource() = 0;
	friend std::ostream& operator<<(std::ostream&, Frame&);
};