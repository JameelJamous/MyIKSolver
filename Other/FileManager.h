#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <optional>
#include "Visitor.h"

using vectOpt = std::optional<std::vector<std::string>>;

class FileManager {

public:
	
	FileManager();
	FileManager(const FileManager& aCopy);
	FileManager(std::string aPath);
	FileManager(const char* aPath);
	FileManager& operator=(const FileManager& aCopy);
	~FileManager();

	FileManager& operator<<(Visitor* aVisitor);

	bool saveContents(std::string aFileName, bool overwrite = false);
	bool loadContents(std::string aFileName);

	void loadInto(Visitor* aVisitor, std::string extracted);
	void save(Visitor* aVisitor);
	


private:
	bool insertToFile(std::string aPath, bool overwrite = false);
	bool extractFromFile(std::string aPath);

	std::string theFolderPath;
	std::string theData;
	std::vector<std::string> fileLines;

	std::list<Visitor*> theVisitorList;

};