#pragma once

#include "../components/Movie.h"
#include <fstream>
#include <iostream>
#include <exception>
#include "../utils/json.hpp"
#include "../app/AppConfig.h"


class JsonHandler
{
private:
   using nl = nlohmann::json;
public:
   static bool readAppConfig(const std::string &file_path, AppConfig *config)
   {
      std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            ifs.open(file_path);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << "\n could not open file: \n"
                      << file_path;
            std::cout << std::endl;
            return false;
        }

        nl jobj = nl::parse(ifs);
        int startYear = jobj["start_year"];
        int endYear = jobj["end_year"];

        config->setStartYear(startYear);
        config->setEndYear(endYear);

        for (auto genres : jobj["genres"])
        {
            std::string genre = genres;
            config->addGenre(genre);
        }

        ifs.close();
        return true;
   }

   static bool constructMovie(const std::string& file_path, Movie *movie)
   {
std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            ifs.open(file_path);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << "\n could not open file: \n"
                      << file_path;
            std::cout << std::endl;
            return false;
        }

        nl jobj = nl::parse(ifs);

        const std::string movie_name = jobj["name"];
        const std::string movie_link = jobj["link"];
        int movie_year = jobj["year"];
        float movie_rating = jobj["rating"];

        movie->setName(movie_name);
        movie->setLink(movie_link);
        movie->setYear(movie_year);
        movie->setRating(movie_rating);

        for (auto elem : jobj["genres"])
        {
            const std::string movie_genre = elem;
            movie->addGenre(elem);
        }
        ifs.close();
        return true;

}
};

