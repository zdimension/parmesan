#include "tester.h"

using namespace std;

void Tester::generateLsl()
{
    m_outFile << "# LSL" << endl;
    for(unsigned int i=0; i<m_nbTests; i++)
    {
        unsigned int imm5=m_distribUnsigned(m_re), rn=m_distribUnsigned(m_re), rd=m_distribUnsigned(m_re);
        m_outFile << "00000" << bitset<5>(imm5) << bitset<3>(rn) << bitset<3>(rd) << " ";
        m_outFile << "0000 0 0 ";
        m_outFile << "0 1 0 " << bitset<5>(imm5) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0010 ";
        m_outFile << "xxx " << bitset<3>(rn) << " " << bitset<3>(rd) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0 0 xxxxxxxx" << endl;
    }
    m_outFile << endl;
}

void Tester::generateLsr()
{
    m_outFile << "# LSR" << endl;
    for(unsigned int i=0; i<m_nbTests; i++)
    {
        unsigned int imm5=m_distribUnsigned(m_re), rn=m_distribUnsigned(m_re), rd=m_distribUnsigned(m_re);
        m_outFile << "00001" << bitset<5>(imm5) << bitset<3>(rn) << bitset<3>(rd) << " ";
        m_outFile << "0000 0 0 ";
        m_outFile << "0 1 0 " << bitset<5>(imm5) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0011 ";
        m_outFile << "xxx " << bitset<3>(rn) << " " << bitset<3>(rd) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0 0 xxxxxxxx" << endl;
    }
    m_outFile << endl;
}

void Tester::generateAdd()
{
    m_outFile << "# ADD" << endl;
    for(unsigned int i=0; i<m_nbTests; i++)
    {
        unsigned int rm=m_distribUnsigned(m_re), rn=m_distribUnsigned(m_re), rd=m_distribUnsigned(m_re);
        m_outFile << "0001100" << bitset<3>(rm) << bitset<3>(rn) << bitset<3>(rd) << " ";
        m_outFile << "0000 0 0 ";
        m_outFile << "0 1 0 " << "xxxxx" << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0101 ";
        m_outFile << bitset<3>(rm) << " " << bitset<3>(rn) << " " << bitset<3>(rd) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0 0 xxxxxxxx" << endl;
    }
    m_outFile << endl;
}

void Tester::generateSub()
{
    m_outFile << "# SUB" << endl;
    for(unsigned int i=0; i<m_nbTests; i++)
    {
        unsigned int rm=m_distribUnsigned(m_re), rn=m_distribUnsigned(m_re), rd=m_distribUnsigned(m_re);
        m_outFile << "0001100" << bitset<3>(rm) << bitset<3>(rn) << bitset<3>(rd) << " ";
        m_outFile << "0000 0 0 ";
        m_outFile << "0 1 0 " << "xxxxx" << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0101 ";
        m_outFile << bitset<3>(rm) << " " << bitset<3>(rn) << " " << bitset<3>(rd) << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0 0 xxxxxxxx" << endl;
    }
    m_outFile << endl;
}
