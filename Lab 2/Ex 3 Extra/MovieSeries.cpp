#include "MovieSeries.h"
#include <iostream>

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < 16) {
        movies[count++] = movie;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << movies[i]->get_name()
            << ", Year: " << movies[i]->get_year()
            << ", Score: " << movies[i]->get_score()
            << ", Length: " << movies[i]->get_length()
            << ", Passed Years: " << movies[i]->get_passed_years()
            << std::endl;
    }
}

void MovieSeries::sort() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (movies[i]->get_passed_years() < movies[j]->get_passed_years()) {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}