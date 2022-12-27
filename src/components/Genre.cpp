#include "Genre.h"

void Genre::setName(std::string name)
{
    m_name = name;
}

void Genre::addMovie(Movie* m)
{
    m_movies.push_back(m);
}

std::string Genre::getName() const
{
    return m_name;
}

int Genre::getMovieCount() const
{
    return m_movies.size();
}

    Genre::MovieVec::iterator Genre::MoviesBegin()
    {
        return m_movies.begin();
    }
    Genre::MovieVec::iterator Genre::MoviesEnd()
    {
        return m_movies.end();
    }
