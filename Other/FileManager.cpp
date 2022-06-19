#include "FileManager.h"


//--------------------------------------------
// Public Methods
//--------------------------------------------

FileManager::FileManager(){ /* Do Nothing*/ }

FileManager::FileManager(const FileManager& aCopy) { *this = aCopy; }

FileManager::FileManager(std::string aPath) { theFilePath = aPath; }

FileManager::FileManager(const char* aPath) { theFilePath = aPath; }

FileManager& FileManager::operator=(const FileManager& aCopy) { theFilePath = aCopy.theFilePath; theData = aCopy.theData;
	return *this;
}

FileManager::~FileManager() { /* Do Nothing */ }


FileManager& FileManager::operator<<(Visitor* aVisitor) {
    theVisitorList.push_back(aVisitor);
    return *this;
}

void FileManager::saveContents(std::string aFileName, bool overwrite) {
    theFilePath.append("\\" + aFileName);
    if (!theFilePath.ends_with(".rob"))
        theFilePath.append(".rob");

    for (auto& item : theVisitorList) {
        save(item);
    }
}

 

void FileManager::save(Visitor* aVisitor) {
	theData.append(aVisitor->save());

    insertToFile((hasContent()) ? true : false); /* put theData in the file */
    
}

void FileManager::loadInto(Visitor* aVisitor) {
    /* extract the correct line from the file and store in theData */
	aVisitor->load(theData);
}





//------------------------------------------------
// Private Members
//------------------------------------------------

bool FileManager::hasContent() {
    std::ifstream inFile(theFilePath);
    inFile.seekg(0, inFile.end);
    long size = inFile.tellg();

    inFile.close();
    return (size > 0) ? true : false;
}

bool FileManager::insertToFile(bool appending) {

    std::ofstream outFile(theFilePath,
        (appending) ? std::ios_base::app : std::ios_base::out);

    if (!(outFile << theData << "\n")) {
        std::cerr << "Failed to write to file" << std::endl;
        outFile.close();
        return false;
    }

    outFile.close();
    return true;
}

bool FileManager::extractFromFile() {
    std::ifstream aFileStream;
    aFileStream.open(theFilePath);
    if (aFileStream.is_open()) {

        // get length of file:
        aFileStream.seekg(0, aFileStream.end);
        int length = aFileStream.tellg();
        aFileStream.seekg(0, aFileStream.beg);

        char* buffer = new char[length];

        std::cout << "Reading " << length << " characters... ";
        // read data as a block:
        aFileStream.read(buffer, length);

        if (aFileStream)
            std::cout << "all characters read successfully.\n";
        else
            std::cout << "error: only " << aFileStream.gcount() << " could be read";
        aFileStream.close();


        std::cout.write(buffer, length);
        // ...buffer contains the entire file...

        theData = buffer;

        delete[] buffer;
        return true;
    }

    return false;
}
