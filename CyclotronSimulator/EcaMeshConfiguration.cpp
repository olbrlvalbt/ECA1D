#include "EcaMeshConfiguration.h"


EcaMeshConfiguration::EcaMeshConfiguration(EcaController* _ecaController)
	: EcaConfiguration(_ecaController) {
	numIterations = 100;
	cellSize = 3;

	deadCellBrush = wxBrush(wxColour(220, 170, 15));
	aliveCellBrush = wxBrush(wxColour(115, 35, 15));
}

EcaMeshConfiguration::EcaMeshConfiguration(EcaController* _ecaController,
		int _numIterations, int _cellSize,
		wxColour _deadCellColor, wxColour _aliveCellColor)
		: EcaConfiguration(_ecaController) {
	numIterations = _numIterations;
	cellSize = _cellSize;

	deadCellBrush = wxBrush(_deadCellColor);
	aliveCellBrush = wxBrush(_aliveCellColor);
}

int EcaMeshConfiguration::getNumIterations() {
	return numIterations;
}

int EcaMeshConfiguration::getCellSize() {
	return cellSize;
}

wxBrush& EcaMeshConfiguration::getDeadCellBrush() {
	return deadCellBrush;
}

wxBrush& EcaMeshConfiguration::getAliveCellBrush() {
	return aliveCellBrush;
}