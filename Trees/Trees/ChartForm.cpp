#include "ChartForm.h"
#include <Windows.h>

using namespace Trees;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew ChartForm);
	return 0;
}