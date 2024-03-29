#include <iostream>
#include <ctime>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;
using Date = std::chrono::time_point<Clock>;
using ms = std::chrono::milliseconds;

int main() {

	float delta;

	Date timeLast;
	Date timeCurrent;

	while (1) {
		system("cls");

		timeLast = timeCurrent;
		timeCurrent = Clock::now();

		delta = std::chrono::duration_cast<ms>(timeCurrent - timeLast).count() / 1000.;
		std::cout << delta << std::endl;
	}

}