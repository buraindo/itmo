#include "Batsman.h"

void Batsman::readData() {
	bool typedGoodCode = false;
	while (!typedGoodCode) {
		cout << "Type 4-digit code, please: ";
		cin >> mCode;
		if (!mIsGoodCode(mCode)) {
			cout << "You've typed an incorrect value! Please, follow the instructions below." << endl;
		}
		else {
			typedGoodCode = true;
		}
	}
	cout << "Type batsman's name, please: ";
	char t[256];
	cin.get();
	cin.getline(t, 256);
	memcpy(mName, t, NAME_LENGTH + 1);
	mName[NAME_LENGTH] = '\0';
	cout << "Type batsman's innings value, please: ";
	cin >> mInnings;
	cout << "Type batsman's notout value, please: ";
	cin >> mNotOut;
	cout << "Type batsman's runs value, please: ";
	cin >> mRuns;
	mAverageValue = mCalculateAverage();
}

void Batsman::displayData() {
	cout << "Code: " << mCode << endl
		<< "Name: " << mName << endl
		<< "Innings: " << mInnings << endl
		<< "Not out: " << mNotOut << endl
		<< "Runs: " << mRuns << endl;
	if (mAverageValue == -1) {
		cout << "Seems like innings and not out values are equal, please, type different values for those" << endl;
	} else cout << "Average: " << mAverageValue << endl;
}

bool Batsman::mIsGoodCode(const string& code) {
	if ((int)code.size() != CODE_LENGTH)
		return false;
	for (int i = 0; i < CODE_LENGTH; i++) {
		if (code[i] < '0' || code[i] > '9') {
			return false;
		}
	}
	return true;
}

float Batsman::mCalculateAverage() {
	return mInnings - mNotOut == 0 ? -1 : (float)mRuns / (mInnings - mNotOut);
}

int main() {
	Batsman batsman;
	batsman.readData();
	batsman.displayData();
	int a;
	cin >> a;
	return 0;
}