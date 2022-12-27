#include "AppConfig.h"

void AppConfig::setStartYear(int year)
{
    m_startingYear = year;
}
void AppConfig::setEndYear(int year)
{
    m_endYear = year;
}
void AppConfig::addGenre(const std::string &genre)
{
    m_genres.push_back(genre);
}

int AppConfig::getStartYear() const
{
    return m_startingYear;
}

int AppConfig::getEndYear() const
{
    return m_endYear;
}


    AppConfig::GenreVec::iterator AppConfig::genresBegin()
    {
        return m_genres.begin();
    }
    AppConfig::GenreVec::iterator AppConfig::genresEnd()
    {
        return m_genres.end();
    }

