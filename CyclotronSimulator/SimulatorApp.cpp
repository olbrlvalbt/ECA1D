#include "SimulatorApp.h"

wxIMPLEMENT_APP(SimulatorApp);

bool SimulatorApp::OnInit() {
	mainFrame = new SimulatorMenu();
	mainFrame->SetAutoLayout(true);
	mainFrame->Show();

	return true;
}
