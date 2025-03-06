#include "movie_utils.h"
#include <cstring>

int movie_compare_name(const Movie& first, const Movie& second) {
    return strcmp(first.get_name(), second.get_name());
}

int movie_compare_year(const Movie& first, const Movie& second) {
    if (first.get_year() < second.get_year()) return -1;
    if (first.get_year() > second.get_year()) return 1;
    return 0;
}

int movie_compare_score(const Movie& first, const Movie& second) {
    if (first.get_score() < second.get_score()) return -1;
    if (first.get_score() > second.get_score()) return 1;
    return 0;
}

int movie_compare_length(const Movie& first, const Movie& second) {
    if (first.get_length() < second.get_length()) return -1;
    if (first.get_length() > second.get_length()) return 1;
    return 0;
}

int movie_compare_passed_years(const Movie& first, const Movie& second) {
    if (first.get_passed_years() < second.get_passed_years()) return -1;
    if (first.get_passed_years() > second.get_passed_years()) return 1;
    return 0;
}