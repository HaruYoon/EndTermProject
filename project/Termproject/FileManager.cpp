#include "FileManager.h"
#include <fstream>
#include <iostream>

// FileManager::run 함수
bool FileManager::run() {
    std::ifstream inFile(inPath); //주석: 입력 파일 열기
    if (!inFile.is_open()) {
        std::cerr << "입력 파일을 열 수 없습니다: " << inPath << std::endl;
        return false;
    }

    std::ofstream outFile(outPath); //주석: 출력 파일 열기
    if (!outFile.is_open()) {
        std::cerr << "출력 파일을 열 수 없습니다: " << outPath << std::endl;
        return false;
    }

    std::string id, name, seq;

    // 파일에서 환자 데이터를 한 줄씩 읽기
    while (std::getline(inFile, id) && std::getline(inFile, name) && std::getline(inFile, seq)) {
        id = id.substr(id.find(":") + 2);   // ID 
        name = name.substr(name.find(":") + 2); // 이름
        seq = seq.substr(seq.find(":") + 2); // 염기서열

        //주석: 객체 포인터 배열: 암세포 객체 배열 생성
        CancerCell* cells[] = {
            new LiverCancerCell(id, name, seq),  // 간암 판별 
            new ColonCancerCell(id, name, seq), // 대장암 판별
            new StomachCancerCell(id, name, seq) // 위암 판별
        };

        // 배열 순회하면서 암 유형 판별
        std::string type = "Unknown";
        for (auto cell : cells) {
            type = cell->identifyType(); 
            if (type != "Unknown") break; // 유형이 판별되면 종료
        }

        // 암 유형이 "Unknown"인 경우 이상 없음 메세지 출력
        if (type == "Unknown") {
            type = "특별한 이상이 없습니다.";
            outFile << "ID: " << id << "\n"
                << "Name: " << name << "\n"
                << "Type: " << type << "\n\n";
        }
        else {
            // 분석 결과 계산 및 출력
            Prognosis prog;
            GrowthRate growth;
            EarlyOnset onset;

            std::string progRes = prog.analyze(seq);
            std::string growthRes = growth.analyze(seq);
            std::string onsetRes = onset.analyze(seq);

            outFile << "ID: " << id << "\n"
                << "Name: " << name << "\n"
                << "Type: " << type << "\n"
                << "예후: " << progRes << "\n"
                << "증식 속도: " << growthRes << "\n"
                << "조기 발병 가능성: " << onsetRes << "\n\n";
        }

        // 주석: 객체 포인터 해제
        for (auto cell : cells) {
            delete cell; // 동적 할당된 객체 해제
        }
    }

    inFile.close(); // 입력 파일 닫기
    outFile.close(); // 출력 파일 닫기
    return true;
}
