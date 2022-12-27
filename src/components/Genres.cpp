#include "Genres.h"

Genres::Genres(std::vector<std::string> &genres)
{
    for(auto genreName : genres)
    {
        Genre* p_genre = new Genre;
        p_genre->setName(genreName);
        m_genres_list.push_back(p_genre);
    }

    auto genreCompare = [](Genre* g1, Genre* g2)
    {
        std::string name1 = g1->getName();
        std::string name2 = g2->getName();
        return name1 < name2;

    };

    std::sort(m_genres_list.begin(), m_genres_list.end(), genreCompare);
}

Genres::~Genres()
{
    for(auto elem : m_genres_list)
    {
        delete elem;
    }
}

Genres::GenreVec::iterator Genres::genresBegin()
{
    return m_genres_list.begin();
}
Genres::GenreVec::iterator Genres::genresEnd()
{
    return m_genres_list.end();
}

   
