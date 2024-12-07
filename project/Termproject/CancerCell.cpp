#include "CancerCell.h"
// �ּ�: CancerCell�� �Ļ� Ŭ�������� ���� �Լ� identifyType ������
std::string LiverCancerCell::identifyType() {
    if (seq.find("TERT") != std::string::npos && seq.find("AXIN1") != std::string::npos) // TERT�� AXIN1 ���ڿ� ��� �߽߰� �������� �Ǻ�
        return "Liver Cancer";
    return "Unknown";
}

std::string ColonCancerCell::identifyType() {
    if (seq.find("CTNNB1") != std::string::npos && seq.find("APC") != std::string::npos) // CTNNB1�� APC ���ڿ� ��� �߽߰� ��������� �Ǻ�
        return "Colon Cancer";
    return "Unknown";
}

std::string StomachCancerCell::identifyType() {
    if (seq.find("CDH1") != std::string::npos && seq.find("APC") != std::string::npos) // CDH1�� APC ���ڿ� ��� �߽߰� �������� �Ǻ�
        return "Stomach Cancer";
    return "Unknown";
}
