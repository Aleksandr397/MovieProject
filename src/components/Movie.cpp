#include "Movie.h"

void Movie::setName(const std::string &name)
{
    m_name = name;
}
void Movie::setYear(int year)
{
    m_year = year;
}
void Movie::setRating(float rating)
{
    m_rating = rating;
}

void Movie::setLink(const std::string& link)
{
    m_link = link;
}

void Movie::addGenre(const std::string &genre)
{
    m_genres.push_back(genre);
}

std::string Movie::getName() const
{
    return m_name;
}
    int Movie::getYear() const
    {
        return m_year;
    }
    float Movie::getRating() const
    {
        return m_rating;
    }
    
    std::string Movie::getLink() const
    {
        return m_link;
    }
    Movie::GenreVec::iterator Movie::genreBegin()
    {
        return m_genres.begin();
    }
    Movie::GenreVec::iterator Movie::genreEnd()
    {
        return m_genres.end();
    }


