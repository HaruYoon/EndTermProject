#include "PrognosisAnalyzer.h"

//Ư�� �������̵� ������ ����Ѵ�.
int countMutations(const std::string& seq, const std::vector<std::string>& mutations) {
    int count = 0;
//for���� ��ȸ�ϸ鼭 ���⼭���� �����ϴ��� Ȯ���Ѵ�
    for (const auto& mut : mutations) {
        if (seq.find(mut) != std::string::npos) {
            count++;
        }
    }
    return count; //������ ��ȯ
}

//������ ���� ��� �Ǵ�
//�ּ�: �Լ� �ߺ�, ���, ���� �Լ�
std::string Prognosis::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "����";
    else if (count <= 2) return "����";
    return "�ſ� ����";
}

std::string GrowthRate::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "����";
    else if (count <= 2) return "����";
    return "�ſ� ����";
}

std::string EarlyOnset::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "����";
    else if (count <= 2) return "�߰�";
    return "����";
}
