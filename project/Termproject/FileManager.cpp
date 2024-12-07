#include "FileManager.h"
#include <fstream>
#include <iostream>

// FileManager::run �Լ�
bool FileManager::run() {
    std::ifstream inFile(inPath); //�ּ�: �Է� ���� ����
    if (!inFile.is_open()) {
        std::cerr << "�Է� ������ �� �� �����ϴ�: " << inPath << std::endl;
        return false;
    }

    std::ofstream outFile(outPath); //�ּ�: ��� ���� ����
    if (!outFile.is_open()) {
        std::cerr << "��� ������ �� �� �����ϴ�: " << outPath << std::endl;
        return false;
    }

    std::string id, name, seq;

    // ���Ͽ��� ȯ�� �����͸� �� �پ� �б�
    while (std::getline(inFile, id) && std::getline(inFile, name) && std::getline(inFile, seq)) {
        id = id.substr(id.find(":") + 2);   // ID 
        name = name.substr(name.find(":") + 2); // �̸�
        seq = seq.substr(seq.find(":") + 2); // ���⼭��

        //�ּ�: ��ü ������ �迭: �ϼ��� ��ü �迭 ����
        CancerCell* cells[] = {
            new LiverCancerCell(id, name, seq),  // ���� �Ǻ� 
            new ColonCancerCell(id, name, seq), // ����� �Ǻ�
            new StomachCancerCell(id, name, seq) // ���� �Ǻ�
        };

        // �迭 ��ȸ�ϸ鼭 �� ���� �Ǻ�
        std::string type = "Unknown";
        for (auto cell : cells) {
            type = cell->identifyType(); 
            if (type != "Unknown") break; // ������ �Ǻ��Ǹ� ����
        }

        // �� ������ "Unknown"�� ��� �̻� ���� �޼��� ���
        if (type == "Unknown") {
            type = "Ư���� �̻��� �����ϴ�.";
            outFile << "ID: " << id << "\n"
                << "Name: " << name << "\n"
                << "Type: " << type << "\n\n";
        }
        else {
            // �м� ��� ��� �� ���
            Prognosis prog;
            GrowthRate growth;
            EarlyOnset onset;

            std::string progRes = prog.analyze(seq);
            std::string growthRes = growth.analyze(seq);
            std::string onsetRes = onset.analyze(seq);

            outFile << "ID: " << id << "\n"
                << "Name: " << name << "\n"
                << "Type: " << type << "\n"
                << "����: " << progRes << "\n"
                << "���� �ӵ�: " << growthRes << "\n"
                << "���� �ߺ� ���ɼ�: " << onsetRes << "\n\n";
        }

        // �ּ�: ��ü ������ ����
        for (auto cell : cells) {
            delete cell; // ���� �Ҵ�� ��ü ����
        }
    }

    inFile.close(); // �Է� ���� �ݱ�
    outFile.close(); // ��� ���� �ݱ�
    return true;
}
