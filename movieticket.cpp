#include <bits/stdc++.h>
using namespace std;

int amount[] = {100,150,200};
class Movie {
public:
    static vector<string> NameOfMovies;
    Movie(string name) {
        NameOfMovies.push_back(name);
        vector<vector<bool>> vec( 10 , vector<bool> (10, 0));
        seat = vec;
    }

    void getSeats() {
        char columnLetter = 'A';
        int rowNumber = 1;
        cout << "\n   SEAT ARRANGEMENTS\n" << endl;
        cout << "   ";
        for (int clm = 0; clm<10; clm++) {
            cout << columnLetter << ' ';
            columnLetter++;
        }
        cout << endl;

        for (auto const rw : seat) {
            printf("%2d ",rowNumber);
            rowNumber++;
            for (auto const elm : rw) {
                cout << elm << ' ';
            }
            if (rowNumber == 4){
                cout << "   SEAT AVAILABLE - 0";
            }
            if (rowNumber == 6){
                cout << "   SEAT BOOKED - 1";
            }
            cout << endl;
        }
        cout << endl;
    }
    int bookSeats(char clm, int row) {
        int col = clm - 'A';
        if (seat[row - 1][col]) {
            cout << "\nALREADY BOOKED!!! PLEASE BOOK ANOTHER SEAT\n" << endl;
            return 0;
        }
        seat[row - 1][col] = true;
        return 1;
    }
    static void getAllNames() {
        int cnt = 1;
        for (auto i : NameOfMovies) {
            cout << "     " << cnt << ' ' << i << " Rs-" << amount[cnt-1] << '\n';
            cnt++;
        }
    }

private:
    vector<vector<bool>> seat;
};
vector<string> Movie::NameOfMovies{};

int main() {
    Movie movies[3] {Movie("THE NUM ll"), Movie("OPPENHIEMER"), Movie("MISSION IMPOSSIBLE")};

   while (true) {
        int selection, clm;
        char rw;
        cout << "\n**************************************************\n" << endl;
        cout << "               MOVIE TICKET BOOKING\n" << endl;
        cout << "**************************************************" << endl;
        cout << "                 SELECT A THEATRE\n" << endl;
        movies->getAllNames();
        cout << "     4 Quit\n" << endl;
        cout << "**************************************************" << endl;
        cout << "Enter the choice of the theatre ";
        cin >> selection;

        if (selection == 4 ) break;
        cout << "Enter the Number of Tickets to be Booked: ";
        int n;
        cin >> n;
        movies[selection-1].getSeats();
        int i=1;
        int temp = 0;
        while (i<=n){
            cout << "ENTER ROW AND COLUMN OF SEAT " << i << "( EG., A5 H8 ) " ;
            cin >> rw >> clm;
            temp = movies[selection-1].bookSeats(rw, clm);  
            if (temp == 0){
                continue;
            }
            else{
                i++;
            }      
        }
        cout << "\n**************************************************************\n" << endl;
        cout << "                      BOOKING BILL\n" << endl;
        cout << "**************************************************************" << endl;
        cout << "\n      Movie Name                        -  " << movies->NameOfMovies[selection-1] << endl;
        printf("\n      Number of Tickets Booked              -  %3d\n",n);
        printf("\n      Cost of Ticket per Person (in Rs)     -  %6.2f\n",(float)amount[selection-1]);
        printf("\n      Tax Percentage (GST) (in %)           -   12 %\n");
        printf("\n      Tax Amount (in Rs)                    -  %6.2f\n",amount[selection-1]*0.12*n);
        printf("_______________________________________________________________\n");
        printf("\n      Total Cost for Tickets Booked (in Rs) -  %6.2f\n",amount[selection-1]*n*1.12);
        printf("_______________________________________________________________\n");
        cout << "\n                Tickets Booked Successfully\n" << endl;
        cout << "                    !!! Thank You !!!" << endl;
        cout << "______________________________________________________________\n" << endl;
        char book;
        cout << "Do you want to book again (y/n) ";
        cin >> book;
        if (book == 'n' || book == 'N'){
            break;
        }
        getc;
   }

    return 0;
}