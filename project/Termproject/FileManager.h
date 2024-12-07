#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include "CancerCell.h"

class FileManager {
private:
    std::string inPath;  // �Է� ���� ���
    std::string outPath; // ��� ���� ���

public:
    FileManager(const std::string& in, const std::string& out)
        : inPath(in), outPath(out) {}
    //���� ó�� �Լ� 
    bool run(); 
};

#endif
