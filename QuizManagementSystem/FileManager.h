#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Quiz.h"

class FileManager {
public:
    static bool saveToFile(const std::vector<Quiz>& quizzes);
    static std::vector<Quiz> loadFromFile();
};

#endif // FILEMANAGER_H
