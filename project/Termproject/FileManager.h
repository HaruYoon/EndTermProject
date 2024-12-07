#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include "CancerCell.h"

class FileManager {
private:
    std::string inPath;  // 입력 파일 경로
    std::string outPath; // 출력 파일 경로

public:
    FileManager(const std::string& in, const std::string& out)
        : inPath(in), outPath(out) {}
    //파일 처리 함수 
    bool run(); 
};

#endif
