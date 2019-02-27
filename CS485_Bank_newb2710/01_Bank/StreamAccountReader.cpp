#include "StreamAccountReader.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

bool StreamAccountReader::openAccountsDB(std::string file) {
	bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;
}
bool StreamAccountReader::read(IAccount &rcAccount) {
	char accountType;
	IAccount *pcAccount = nullptr;
	while (mcInFile >> accountType) {
		switch (accountType) {
			case 'S':
				pcAccount = new SavingsAccount();
				break;
			case 'C':
				pcAccount = new CheckingAccount();
				break;
		}
		mcInFile >> pcAccount;
	}
	/*char shapeType;
	Shape *pcShape = nullptr;
	while (mTheData >> shapeType)
	{
		switch (shapeType)
		{
		case 'S':
			pcShape = new Square();
			break;
		case 'C':
			pcShape = new Circle();
			break;
		}
		mTheData >> *pcShape;
		rcCol.addShape(pcShape);*/
}
bool StreamAccountReader::closeAccountsDB() {
	mcInFile.close();
}