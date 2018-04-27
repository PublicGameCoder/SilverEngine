#ifndef TIME_H
#define TIME_H

//Include OpenGL
#include <OpenGLInc.h>

#include <SEConfig.h>

class Time
{
public:
	static float deltaTime;
	static void calcDelta();

	static void pause() {
		_paused = true;
	}
	static void unpause() {
		_paused = false;
	}

private:
	static bool _paused;
	static bool _prevState;
};

#endif // !TIME_H
