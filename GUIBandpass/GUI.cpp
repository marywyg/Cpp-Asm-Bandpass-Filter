#include "GUI.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main2() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUIBandpass::GUI form;
	Application::Run(% form);
}