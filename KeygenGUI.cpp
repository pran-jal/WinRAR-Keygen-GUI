#include "KeygenGUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array <String^>^ argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KeygenGUI::KeygenGUI form;
	Application::Run(% form);
}