#include "EcaFrame.h"

EcaFrame::EcaFrame(EcaLogic* ecaLogic, int numIterations, int cellSize = 1,
				   wxColour deadCellColor = wxColour(220, 170, 15),
				   wxColour aliveCellColor = wxColour(115, 35, 15),
				   wxColour filterExteriorColor = wxColour(15, 15, 95),
				   wxColour filterInteriorColor = wxColour(45, 45, 120))
		: wxFrame(nullptr, wxID_ANY, wxT("ECA R" + to_string(ecaLogic->ruleNumber) + " - N: " + to_string(ecaLogic->N)),
				  wxDefaultPosition, wxDefaultSize) {
	wxBoxSizer* frameSizer = new wxBoxSizer(wxHORIZONTAL);

	drawPanel = new DrawPanel(this, ecaLogic, numIterations, cellSize,
		deadCellColor, aliveCellColor,
		filterExteriorColor, filterInteriorColor);
	frameSizer->Add(drawPanel, 1, wxALL | wxEXPAND);
	SetSizer(frameSizer);
	wxSize panelSize = drawPanel->GetClientSize();
	wxSize frameSize = panelSize;
	if (panelSize.x > MaxFrameSize.x) {
		frameSize.x = MaxFrameSize.x;
	}
	if (panelSize.y > MaxFrameSize.y) {
		frameSize.y = MaxFrameSize.y;
	}
	SetClientSize(frameSize);
	SetMaxClientSize(panelSize);
	Center();
}