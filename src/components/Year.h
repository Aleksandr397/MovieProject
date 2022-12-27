#pragma once

#include "Movie.h"
#include <string>
#include <vector>

class Year 
{
private:
    using MovieVec = std::vector<Movie *>;
public:
    void setYear(int year);
    void addMovie(Movie* m);
    
    int getYear() const;
    int getMovieCount() const;
    MovieVec::iterator MoviesBegin();
    MovieVec::iterator MoviesEnd();


private:
    int m_year;
    std::vector<Movie *> m_movies;
};

