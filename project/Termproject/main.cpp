/*
컴퓨터 프로그래밍 및 실습 평가과제 (배점 25점)
학과: 컴퓨터 전자시스템 공학과
학번: 202003617
이름: 최태윤
과제 주제: 이 프로그램은 미래에 유전자 분석 기술을 통해서 환자 차트를 입력 받고 수 많은 유전자들을 분석해 돌연변이 염기서열들을 분석하고 찾아내어, 걸릴 수 있는 암을 분류하고 
해당 암에 대한 예후와 진행 속도, 그리고 발병 시기 등을 분석해서 출력해주는 프로그램이다. 이를 통해 사람들은 언제든 현재 자기의 건강 상태를 확인할 수 있고, 이를 예방하고 혹은 조기 치료를 통해서
생존 확률을 높일 수 있다. 입력 파일로는 환자의 아이디와 이름, 그리고 유전자 염기서열이 입력으로 주어지고 이를 분석하여 특정 암에 해당하는 조건이 충족될 때, 분류하게 된다. 이 프로그램에서는
간암, 대장암, 위암 3가지를 중심으로 프로그램을 작성하였으며, 각각 특정 유전자 배열이 동시에 존재하게 되면, 판정하는 것으로 하였다. 예후와 증식 속도, 발병 시기 같은 경우 각각에 해당하는 염기서열이
0개, 1~2개, 3~5개 일 때로 구분하여 좋음, 보통, 나쁨으로 출력해주도록 설정해주었다. 
*/

#include <iostream>
#include <stdexcept> 
#include "FileManager.h"

int main() {
    try {
        std::string inPath, outPath;

        // 파일 입력과 파일 출력 경로를 입력받음
        std::cout << "환자 파일: ";
        std::getline(std::cin, inPath);

        std::cout << "분석 결과: ";
        std::getline(std::cin, outPath);

        // FileManager 객체 생성
        FileManager fm(inPath, outPath);

        // run() 실행 및 예외 처리
        if (!fm.run()) {
            throw std::runtime_error("파일 분석 중 오류 발생");
        }

        std::cout << "분석 완료" << std::endl;
    }
    catch (const std::exception& e) { //예외 처리
        std::cerr << "예외 발생: " << e.what() << std::endl; 
        return 1;
    }
    catch (...) { 
        std::cerr << "알 수 없는 예외 발생" << std::endl;
        return 1; 
    }

    return 0; 
}
