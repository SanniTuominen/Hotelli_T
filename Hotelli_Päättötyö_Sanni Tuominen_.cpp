// Sanni Tuominen
// Hotellin varausj‰rjestelm‰n lopputyˆ
//3 p arvoinen

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
//M‰‰ritell‰‰n liikkuvat komponentit eli minimi ja maksimi m‰‰r‰t huoneiden ja hintojen arvoille 
int MIN_Huoneet = 30;
int MAX_Huoneet = 70;
int MIN_Hinta = 80;
int MAX_Hinta = 100;

int arvoVapaaHuone(vector<bool> huoneet) {  //T‰ss‰ komponentissa arvotaan huoneiden m‰‰r‰ ja lis‰t‰‰n ne listalle 
    vector<int> vapaat;
    for (int i = 0; i < huoneet.size(); i++) {
        if (!huoneet[i]) {
            vapaat.push_back(i + 1); 
        }
    }
    if (vapaat.empty()) { // Ohjelma tarkistaa vapaiden huoneiden m‰‰r‰n ja ilmoittaa jos niit‰ ei ole. Palauttaa arvolla -1
        return -1;
    }
    return vapaat[rand() % vapaat.size()]; //asiakkaalle arvotaan vapaan huoneen numero
}

int main() {
    setlocale(LC_ALL, "FI_fi");// otetaan ‰‰kkˆset k‰yttˆˆn
    srand(time(0));

    // Arvotaan satunnaisesti hotellin huoneiden m‰‰r‰ ja hinnat
    int huoneidenMaara = rand() % (MAX_Huoneet - MIN_Huoneet + 1) + MIN_Huoneet;
    int hintaPerYˆ = rand() % (MAX_Hinta - MIN_Hinta + 1) + MIN_Hinta;

    vector<bool> huoneet(huoneidenMaara);

    // Tervehdit‰‰n asiakasta
    cout << "Heippa! Meill‰ on t‰ll‰ hetkell‰ " << huoneidenMaara << " huonetta vapaana ja yksi yˆ maksaa " << hintaPerYˆ << " euroa.\n";


    //T‰h‰n kokosin ohjelman p‰‰ silmukan 
    while (1) {
        cout << "Haluatko huoneen? (k/e): ";
        string vastaus;
        cin >> vastaus;

        if (vastaus == "e") { 
            break;
        }
        if (vastaus != "k") { //jos vastaus ei ole k tai e niin ohjelma antaa virhe ilmauksen 
            cout << "Anteeksi! Syˆte on ep‰selke‰.\n";
            continue;
        }

        //arvotaan vapaana oleva huone
        int huone = arvoVapaaHuone(huoneet);
        if (huone == -1) {
            cout << "Voi ei! Kaikki huoneet varattuna :(\n";
            break;
        }

        
        cout << "Saat k‰yttˆˆsi huoneen nro. " << huone << "!\n";

        //t‰ss‰ tarkistetaan asiakkaan antamien tietojen oikeellisuus ja ohitetaan virhe 
        int oita;
        while (1) {
            cout << "Kuinka monta yˆt‰ ajattelit viipy‰? ";
            cin >> oita;
            if (cin.fail() || oita <= 0) {
                cin.clear();
                cin.ignore(99999, '\n'); 
                cout << "Anteeksi! Syˆte oli taas ep‰selke‰.\n";
            }
            else {
                break;
            }
        }

        //toteutetaan laskukaava yˆpymisen hinnalle ja varmistetaan varaus asiakkaalta
        int summa = oita * hintaPerYˆ;
        cout << "Huone numerolla " << huone << " maksaa " << summa << " euroa yˆpymisesi ajalta.\n";


        cout << "Haluatko varata huoneen? (k/e): ";
        cin >> vastaus;

        if (vastaus == "k") {
            huoneet[huone - 1] = true; //Merkit‰‰n huone varatuksi 
            cout << "Huone numerolla " << huone << " on varattu sinulle. Mukavaa viipymist‰!\n";
        }
        else {
            cout << "Selv‰, huonetta ei varattu. Kiitos asioinnista!\n"; //Jos asiakas ei halua huonetta
        }

        // Otetaan seuraava asiakas jonosta sis‰‰n 
        cout << "\nSeuraava asiakas, kiitos!\n";
    }
    //hyv‰stely viesti
    cout << "Kiitos kun asioit meill‰! N‰hd‰‰n taas pian!\n";
    return 0;
}

