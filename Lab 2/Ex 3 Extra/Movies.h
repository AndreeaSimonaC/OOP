
using namespace std;

class Movie {
private:
    char name[257];
    int releaseYear;
    double imdbScore;
    int lengthMinutes;

public:
    void set_name(const char* name);
    const char* get_name() const;

    void set_year(int year);
    int get_year() const;

    void set_score(double score);
    double get_score() const;

    void set_length(int length);
    int get_length() const;

    int get_passed_years() const;
};

