#pragma once

#include <vector>
#include "Genre.h"
#include <string>
#include <algorithm>

class Genres
{
private:
    using GenreVec = std::vector<Genre *>;
public:
    Genres(std::vector<std::string> &genres);
    ~Genres();
public:
    GenreVec::iterator genresBegin();
    GenreVec::iterator genresEnd();
private:
    std::vector<Genre*> m_genres_list;
};

