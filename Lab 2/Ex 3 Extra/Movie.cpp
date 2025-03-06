#include "Movie.h"
#include <cstring>
#include <ctime>

void Movie::set_name(const char* name) {
    strncpy(this->name, name, 256);
    this->name[256] = '\0';
}

const char* Movie::get_name() const {
    return name;
}

void Movie::set_year(int year) {
    releaseYear = year;
}

int Movie::get_year() const {
    return releaseYear;
}

void Movie::set_score(double score) {
    if (score >= 1.0 && score <= 10.0) {
        imdbScore = score;
    }
}

double Movie::get_score() const {
    return imdbScore;
}

void Movie::set_length(int length) {
    lengthMinutes = length;
}

int Movie::get_length() const {
    return lengthMinutes;
}

int Movie::get_passed_years() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    return currentYear - releaseYear;
}