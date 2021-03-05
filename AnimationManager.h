// AnimationManager.h
#pragma once

class AnimationManager
{
	std::string managerName;
	std::vector<Animation> animations;
public:
	AnimationManager(std::string name) :managerName(name) {}
	~AnimationManager() {}
	void EditAnimation();
	void DeleteAnimation();
	friend std::istream& operator>>(std::istream&, AnimationManager&);// add an Animation
	friend std::ostream& operator<<(std::ostream&, AnimationManager&);// output the Animations
};

