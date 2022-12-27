#include "Years.h"
#include <algorithm>


Years::Years(int startYear, int endYear)
{
    for(int i = startYear; i <= endYear; ++i)
    {
        Year* y = new Year();
        y->setYear(i);
        m_years_list.push_back(y);

    }
    auto sortYears = [](Year* y1, Year* y2){
        return y1->getYear() < y2->getYear();
    };
    std::sort(m_years_list.begin(),m_years_list.end(), sortYears);
}

Years::~Years()
{
    int size = m_years_list.size();
    for(int i = 0; i < size; ++i)
    {
        delete m_years_list[i];
    }
}

Years::YearsVec::iterator Years::yearsBegin()
{
    return m_years_list.begin();
}

Years::YearsVec::iterator Years::yearsEnd()
{
    return m_years_list.end();
}
