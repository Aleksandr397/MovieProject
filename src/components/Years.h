#pragma once

#include <vector>
#include "Year.h"

class Years
{
private:
    using YearsVec = std::vector<Year *>;
public:
    Years(int startYear, int endYear);
    ~Years();
public:
    YearsVec::iterator yearsBegin();
    YearsVec::iterator yearsEnd();

private:
    std::vector<Year*> m_years_list;
};
