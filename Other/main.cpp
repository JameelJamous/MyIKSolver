#include "FileManager.h"
#include "Joint.h"

int main() {

	std::string theFolderPath = "C:\\Users\\Jameel\\Desktop\\Summer2022";
	FileManager aFileManager(theFolderPath);

	Joint joint1(10.0, 150.0, 0.0, "revolute");
	Joint joint2(10.0, 150.0, 0.0, "revolute");
	Joint joint3(150.0, 180.0, 0.0, "prismatic");

	// aFileManager(MCUData, &joint1, &joint2, &joint3)
	// aFileManager.saveContents(std::string aFileName, bool overwrite);
	// aFileManager.loadContents()

	aFileManager << &joint1 << &joint2 << &joint3;
	aFileManager.saveContents("aTestName.rob", false);
	return 0;
}