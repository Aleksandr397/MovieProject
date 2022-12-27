#pragma once

#include "Movie.h"
#include <string>
#include <vector>


class Genre
{
private:
    using MovieVec = std::vector<Movie *>;
public:
    void setName(std::string name);
    void addMovie(Movie* m);

    std::string getName() const;
    int getMovieCount() const;
    MovieVec::iterator MoviesBegin();
    MovieVec::iterator MoviesEnd();



private:
    std::string m_name;
    std::vector<Movie *> m_movies;
};