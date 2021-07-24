/*********************************************************************
* Project:   WinRAR-Keygen-GUI
* Author:     Pranjal (https://github.com/pran-jal)
*********************************************************************/

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
