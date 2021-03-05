# Animation-Inheritance
Animation in C++ with Inheritance.

This is a development of project with the addition of two additional classes AudioFrame and VideoFrame that are derived from the abstract base class Frame and implement polymorphic inheritance. It is a console application that has an AnimationManager that holds a vector template of Animation objects each of which holds a forward_list template of Frame* each of which points to either an AudioFrame or a VideoFrame. Polymorphism is implemented via the pure virtual function void Frame::CalculateFrameResources() of the abstract base class. The string class is used for all the strings in the application.
