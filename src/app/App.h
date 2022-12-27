#pragma once

#include "../components/Movies.h"
#include "../components/Genres.h"
#include "../components/Years.h"
#include "../utils/JsonHandler.h"
#include "AppConfig.h"
#include <string>

class App
{
public:
    App(const std::string& config_path = "../utils/app_config.json");
    ~App();
public:
    void init(const std::string& data_path = "../../data/");

private:
    Movies* m_movies;
    Genres* m_genres;
    Years* m_years;
    AppConfig *m_config;

};
