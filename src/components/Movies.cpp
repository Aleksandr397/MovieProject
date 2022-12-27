#include "Movies.h"

void Movies::addMovie(Movie* m)
{
    m_movie_list.push_back(m);
}

int Movies::getMovieCount() const
{
    return m_movie_list.size();
}

Movies::MovieVec::iterator Movies::MoviesBegin()
{
    return m_movie_list.begin();
}

Movies::MovieVec::iterator Movies::MoviesEnd()
{
    return m_movie_list.end();
}
