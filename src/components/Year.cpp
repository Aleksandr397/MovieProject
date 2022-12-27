#include "Year.h"



int Year::getYear() const
{
    return m_year;
}

void Year::addMovie(Movie* m)
{
    m_movies.push_back(m);
}

void Year::setYear(int year)
{
    m_year = year;
}

int Year::getMovieCount() const
{
    return m_movies.size();
}

Year::MovieVec::iterator Year::MoviesBegin()
{
    return m_movies.begin();
}

Year::MovieVec::iterator Year::MoviesEnd()
{
    return m_movies.end();
}