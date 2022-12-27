#pragma once

#include "Movie.h"
#include <vector>

class Movies
{
private:
    using MovieVec = std::vector<Movie *>;
public:
MovieVec::iterator MoviesBegin();
void addMovie(Movie* m);
int getMovieCount() const;
MovieVec::iterator MoviesEnd();

private:
    std::vector<Movie *> m_movie_list;
};