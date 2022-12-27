#pragma once

#include <string>
#include <vector>

class AppConfig
{
private:
    using GenreVec = std::vector<std::string>;
public:
    void setStartYear(int year);
    void setEndYear(int year);
    void addGenre(const std::string &genre);

    int getStartYear() const;
    int getEndYear() const;
    GenreVec::iterator genresBegin();
    GenreVec::iterator genresEnd();

private:
    int m_startingYear;
    int m_endYear;
    std::vector<std::string> m_genres;
};