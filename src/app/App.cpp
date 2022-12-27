#include "App.h"
#include <filesystem>
#include <fstream>

App::App(const std::string& config_path)
{
    m_config = new AppConfig;
    if(!JsonHandler::readAppConfig(config_path, m_config))
    {
        return;
    }

    m_movies = new Movies;
    m_years = new Years(m_config->getStartYear(), m_config->getEndYear());
    std::vector<std::string> genres;
    for(auto i = m_config->genresBegin(); i != m_config->genresEnd(); ++i)
    {
        genres.push_back(*i);
    }
    m_genres = new Genres(genres);
}

App::~App()
{
    delete m_genres;
    delete m_years;
    delete m_config;
    for(auto it = m_movies->MoviesBegin(); it != m_movies->MoviesEnd(); ++it)
    {
        delete *it;
    } 
    delete m_movies;
}

void App::init(const std::string &data_path)
{
    for(const auto &entry : std::filesystem::directory_iterator(data_path))
    {
        Movie* p_movie = new Movie;
        
        
        JsonHandler::constructMovie(entry.path(), p_movie);
        m_movies->addMovie(p_movie);

        int year = p_movie->getYear();

        auto findYear = [&year](Year* y){
            return y->getYear() == year;
        };
        
        auto yearIt = std::find_if(m_years->yearsBegin(), m_years->yearsEnd(),findYear);
        if(yearIt != m_years->yearsEnd())
        {
            (*yearIt)->addMovie(p_movie);
        }

        for(auto mgIt = p_movie->genreBegin(); mgIt != p_movie->genreEnd(); ++mgIt)
        {
            std::string movieGenre = *mgIt;
            auto findGenre = [&movieGenre](Genre* g){
                return g->getName() == movieGenre;
            };
            auto genreIt = std::find_if(m_genres->genresBegin(),m_genres->genresEnd(), findGenre);
            if(genreIt != m_genres->genresEnd())
            {
                (*genreIt)->addMovie(p_movie);
            }
        
        
        }
    }

  /*  for(auto it = m_movies->MoviesBegin(); it != m_movies->MoviesEnd();++it)
    {
        Movie* m = *it;
        std::cout << "Name: " << m->getName() << std::endl;
        std::cout << "Year: " << m->getYear() << std::endl;
        std::cout << "Rating: " << m->getRating() << std::endl;
        std::cout << "Genres: ";
        for(auto itGenre = m->genreBegin(); itGenre != m->genreEnd(); ++itGenre)
        {
            std::cout << (*itGenre) << " ";
        }
        std::cout << std::endl;
        std::string openLink = "open -a Safari " + m->getLink();
        system(openLink.c_str()); 
    }
    */
    
}
