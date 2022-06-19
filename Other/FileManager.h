#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include "Visitor.h"

class FileManager {

public:
	
	FileManager();
	FileManager(const FileManager& aCopy);
	FileManager(std::string aPath);
	FileManager(const char* aPath);
	FileManager& operator=(const FileManager& aCopy);
	~FileManager();

	FileManager& operator<<(Visitor* aVisitor);

	void saveContents(std::string aFileName, bool overwrite = false);
	void loadContents();

	void loadInto(Visitor* aVisitor);
	void save(Visitor* aVisitor);
	


private:
	bool hasContent();
	bool insertToFile(bool appending = false);
	bool extractFromFile();

	std::string theFilePath;
	std::string theData;

	std::list<Visitor*> theVisitorList;

};