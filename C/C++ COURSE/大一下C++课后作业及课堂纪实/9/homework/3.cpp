//problem 9-3
#include <iostream>
#include <string>
using namespace std;
class Film
{
public:
    Film(string t, string d, int tm, int le) : Title(t), Director(d), Time(tm), level(le) {}
    Film(Film &a)
    {
        Title = a.Title;
        Director = a.Director;
        Time = a.Time;
        level = a.level;
    }
    virtual void output()
    {
        cout << "Title:" << Title << endl;
        cout << "Director:" << Director << endl;
        cout << "Time:" << Time << "mins" << endl;
        cout << "Quality:";
        for (int i = 0; i < level; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    static int read_input(Film **a, int n);

protected:
    string Title;
    string Director;
    int Time;
    int level;
};
class ForeignFilm : public Film
{
public:
    ForeignFilm(string t, string d, int tm, int le, string lang) : Film(t, d, tm, le), language(lang) {}
    ForeignFilm(ForeignFilm &a) : Film(a)
    {
        language = a.language;
    }
    void output()
    {
        cout << "Title:" << Title << endl;
        cout << "Director:" << Director << endl;
        cout << "Time:" << Time << " mins" << endl;
        cout << "Quality:";
        for (int i = 0; i < level; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Language:" << language << endl;
    }

private:
    string language;
};
class DirectorCut : public Film
{
public:
    DirectorCut(string t, string d, int tm, int le, int re, string ch) : Film(t, d, tm, le), Revisedtime(re), chang(ch) {}
    DirectorCut(DirectorCut &a) : Film(a)
    {
        Revisedtime = a.Revisedtime;
        chang = a.chang;
    }
    void output()
    {
        cout << "Title:" << Title << endl;
        cout << "Director:" << Director << endl;
        cout << "Time:" << Time << "mins" << endl;
        cout << "Quality:";
        for (int i = 0; i < level; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Revised time:" << Revisedtime << endl;
        cout << "Changes:" << chang << endl;
    }

private:
    int Revisedtime;
    string chang;
};
int Film::read_input(Film **a, int n)
{
    int choice;
    string Titl;
    string Directo;
    int Tim;
    int leve;
    string languag;
    int revisedtim;
    string chan;
    int ans;
    for (int i = 0; i < n; i++)
    {
        cout << "choice: ";
        cin >> choice;
        getchar();
        if (choice == 4)
        {
            ans = i;
            break;
        }
        cout << "title: ";
        getline(cin, Titl);
        cout << "director: ";
        getline(cin, Directo);
        cout << "tim: ";
        cin >> Tim;
        cout << "level: ";
        cin >> leve;
        if (choice == 1)
        {
            a[i] = new Film(Titl, Directo, Tim, leve);
            continue;
        }
        if (choice == 2)
        {
            getchar();
            cout << "language: ";
            getline(cin, languag);
            a[i] = new ForeignFilm(Titl, Directo, Tim, leve, languag);
            continue;
        }
        if (choice == 3)
        {
            cout << "revisetime: ";
            cin >> revisedtim;
            getchar();
            cout << "change: ";
            getline(cin, chan);
            a[i] = new DirectorCut(Titl, Directo, Tim, leve, revisedtim, chan);
            continue;
        }
    }
    return ans;
}
int main()
{
    const unsigned n = 5;
    Film *films[n];
    int num = Film::read_input(films, n);
    cout << "-------------------\n";
    for (int i = 0; i < num; i++)
    {
        films[i]->output();
        cout << "-------------------\n";
    }
    return 0;
}