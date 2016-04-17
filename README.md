# cpp_11_14_feature_test
[![](https://travis-ci.org/TomSmartBishop/cpp_11_14_feature_test.svg)](https://travis-ci.org/TomSmartBishop/cpp_11_14_feature_test)

This is sample code for the 1st SSPN meetup:
http://www.meetup.com/Seoul-System-Programmers-Network/events/230165622/

It is by no means a complete feature overview on C++11/14, just code to demonstrate some of the new concepts I found important to point out. If you want more, please feel welcome. There is also no focus on the new standard library functionality. So maybe some point later we have time to look at these.

#Notice
 * This is currently work in progress
 * It still misses a lot of thing I would like to talk about
 * But maybe it is already too much for the first time and we have to split it up into more sessions...
 
#Build
 * clone the repro
 * open a console and create a sub directory 'build' and switch to that directory
 * Run the command 'cmake .. -G "Visual Studio 14 2015"' and open the solution in VS2015 on Windows and 'cmake .. -G "Unix Makefiles" && make' on Linux
 
#Source
 * I added a bunch of comments to the source code, but I'm not sure if it understandable without hearing the explaination
 * I tried to introduce new concepts step by step, so we will not through in all 'new' features at once

#Tests
 * Tested most of the time with MSVC 14, GCC6 and clang 3.8.0 - the whole code is written as feature test, if it compiles we are good. Running the executeable in debug modde just prooves some concepts.

#Further Resources
 * A very complete resource list for C++: https://github.com/fffaraz/awesome-cpp
