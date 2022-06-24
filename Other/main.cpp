#include "FileManager.h"
#include "Joint.h"

int main() {

	std::string theFolderPath = "C:\\Users\\Jameel\\Desktop\\Summer 2022";
	FileManager aFileManager(theFolderPath);
	
	Joint joint1(10.0, 150.0, 0.0, "revolute");
	Joint joint2(10.0, 150.0, 0.0, "revolute");
	Joint joint3(150.0, 180.0, 0.0, "prismatic");

	aFileManager << &joint1 << &joint2 << &joint3;
	aFileManager.saveContents("anotherTest", true);
	aFileManager.loadContents("anotherTest");
	return 0;
}