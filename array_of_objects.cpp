#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Movie
{
private:
    string screenWriter;
    int yearReleased;
    string title;

public:
    Movie() {}
    Movie(string screenWrite, int yearReleased, string title)
    {
        this->screenWriter = screenWriter;
        this->yearReleased = yearReleased;
        this->title = title;
    }
    string getScreenWriter()
    {
        return this->screenWriter;
    }
    int getYearReleased()
    {
        return this->yearReleased;
    }
    string getTitle()
    {
        return this->title;
    }
    void setScreenWriter(string screenWriter)
    {
        this->screenWriter = screenWriter;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setYearRealesed(int yearReleased)
    {
        this->yearReleased = yearReleased;
    }
};

int main()
{
    ifstream fin;
    fin.open("movie.txt");
    string screenWriter,title;
    int yearReleased;
    Movie movie[4];
    int i,j = 0;
    while (i < 4)
    {
        getline(fin,screenWriter);
        movie[i].setScreenWriter(screenWriter);
        fin >> yearReleased;
        movie[i].setYearRealesed(yearReleased);
        // fin >> title;
        fin.ignore();
        getline(fin,title);
        movie[i].setTitle(title);
        i++;
    }
    cout << endl
         << "Reading the input file." << endl
         << "...... OK DONE." << endl;
    while (j < 4)
    {
        cout << endl
             << "Movie: " << movie[j].getTitle() << endl;
        cout << endl
             << "\t > Year Released : " << movie[j].getYearReleased() << endl;
        cout << endl
             << "\t > Screen Writer : " << movie[j].getScreenWriter() << endl;
        j++;
    }
    return 0;
}