#pragma once

#include <string>
#include <vector>


class Movie
{
private:
    using GenreVec = std::vector<std::string>;
public:
    void setName(const std::string &name);
    void setYear(int year);
    void setRating(float rating);
    void setLink(const std::string& link);
    void addGenre(const std::string &genre);

    std::string getName() const;
    int getYear() const;
    float getRating() const;
    std::string getLink() const;
    GenreVec::iterator genreBegin();
    GenreVec::iterator genreEnd();


private:
    std::string m_name;
    int m_year;
    float m_rating;
    GenreVec m_genres;
    std::string m_link;
};
