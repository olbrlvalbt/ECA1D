#include "stdafx.h"
#include "Rule110Basic.h"
#include <algorithm>

string Rule110Basic::GetEther(int _multiple) {
	return GetMultiple(Rule110Constants::singleton().ETHER_F1_1, _multiple);
}

string Rule110Basic::GetMultiple(string _expression, int _multiple) {
	if (_expression.empty()) {
		return "";
	}

	if (!IsBinaryString(_expression)) {
		throw InvalidTokenException(_expression);
	}

	string multipleString = "";
	for (int i = 0; i < _multiple; i++) {
		multipleString += _expression;
	}

	return multipleString;
}

bool Rule110Basic::IsBinaryString(string& _s) {
	return regex_match(_s, Rule110Constants::singleton().REGEX_BINARY);
}

bool Rule110Basic::IsEther(string& _s) {
	return regex_match(_s, Rule110Constants::singleton().REGEX_ETHER);
}


void Rule110Basic::Trim(string& _s) {
	_s.erase(remove_if(_s.begin(), _s.end(), [](unsigned char c) {
		return isspace(c);
	}), _s.end());
}


void Rule110Basic::ToLower(string & _s) {
	transform(_s.begin(), _s.end(), _s.begin(), [](unsigned char c) {
		return tolower(c);
	});
}

void Rule110Basic::ToLower(char & _c) {
	_c = tolower(_c);
}


void Rule110Basic::ToUpper(string & _s) {
	transform(_s.begin(), _s.end(), _s.begin(), [](unsigned char c) {
		return toupper(c);
	});
}

void Rule110Basic::ToUpper(char & _c) {
	_c = toupper(_c);
}

