#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cctype>
#include <vector>
#include <string>
#include <complex> 
using namespace std;
unsigned long long faktorial(int n) {
    if (n < 0) return 0; 
    unsigned long long hasil = 1;
    for (int i = 2; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}
void tampilkanMenu() {
    cout << "\n\033[1;36m========================================\033[0m\n";
    cout << "          \033[1;33m📌 KALKULATOR CERDAS 📌\033[0m       \n";
    cout << "\033[1;36m========================================\033[0m\n";
    cout << setw(10) << "\033[1;32m[+]\033[0m  Penjumlahan" << setw(15) << "\033[1;32m[-]\033[0m  Pengurangan\n";
    cout << setw(10) << "\033[1;32m[*]\033[0m  Perkalian"   << setw(15) << "\033[1;32m[/]\033[0m  Pembagian\n";
    cout << setw(10) << "\033[1;32m[^]\033[0m  Pangkat"     << setw(15) << "\033[1;32m[s]\033[0m  Akar Kuadrat\n";
    cout << setw(10) << "\033[1;32m[sin]\033[0m Sinus"      << setw(15) << "\033[1;32m[cos]\033[0m Cosinus\n";
    cout << setw(10) << "\033[1;32m[tan]\033[0m Tangent"    << setw(15) << "\033[1;32m[log]\033[0m Logaritma Natural (ln)\n";
    cout << setw(10) << "\033[1;32m[!]\033[0m  Faktorial"   << setw(15) << "\033[1;32m[c]\033[0m  Bilangan Kompleks\n";
    cout << setw(10) << "\033[1;32m[conv]\033[0m Konversi Satuan" << setw(15) << "\033[1;32m[q]\033[0m  Keluar\n";
    cout << "\033[1;36m========================================\033[0m\n";
}
void tampilkanRiwayat(const vector<string>& riwayat) {
    cout << "\n\033[1;35m📜 Riwayat Perhitungan:\033[0m\n";
    for (const string& entry : riwayat) {
        cout << "  - " << entry << endl;
    }
}
void konversiSatuan() {
    double nilai;
    string dari, ke;
    cout << "Masukkan nilai: ";
    cin >> nilai;
    cout << "Masukkan satuan asal (e.g., km, m, cm): ";
    cin >> dari;
    cout << "Masukkan satuan tujuan (e.g., km, m, cm): ";
    cin >> ke;
    if (dari == "km" && ke == "m") {
        cout << "📌 Hasil: " << nilai << " km = " << nilai * 1000 << " m\n";
    } else if (dari == "m" && ke == "cm") {
        cout << "📌 Hasil: " << nilai << " m = " << nilai * 100 << " cm\n";
    } else {
        cout << "❌ Error! Konversi satuan tidak didukung.\n";
    }
}
int main() {
    string operasi;
    double angka1, angka2;
    vector<string> riwayat; 
    do {
        tampilkanMenu();
        cout << "Masukkan pilihan operasi: ";
        cin >> operasi;
        for (char &c : operasi) c = tolower(c);
        if (operasi == "q") {
            cout << "\033[1;33m📌 Terima kasih telah menggunakan kalkulator ini! 📌\033[0m\n";
            tampilkanRiwayat(riwayat);
            break;
        }
        if (operasi == "conv") {
            konversiSatuan();
            continue;
        }
        if (operasi == "s" || operasi == "sin" || operasi == "cos" || operasi == "tan" || operasi == "log" || operasi == "!") {
            cout << "Masukkan angka: ";
            while (!(cin >> angka1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "⚠️  Input tidak valid. Masukkan angka: ";
            }
        }
        else if (operasi == "+" || operasi == "-" || operasi == "*" || operasi == "/" || operasi == "^") {
            cout << "Masukkan angka pertama: ";
            while (!(cin >> angka1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "⚠️  Input tidak valid. Masukkan angka pertama: ";
            }
            cout << "Masukkan angka kedua: ";
            while (!(cin >> angka2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "⚠️  Input tidak valid. Masukkan angka kedua: ";
            }
        }
        else if (operasi == "c") {
            double real1, imag1, real2, imag2;
            cout << "Masukkan bagian real dan imajiner dari bilangan pertama (e.g., 3 4): ";
            cin >> real1 >> imag1;
            cout << "Masukkan bagian real dan imajiner dari bilangan kedua (e.g., 1 2): ";
            cin >> real2 >> imag2;
            complex<double> bil1(real1, imag1), bil2(real2, imag2);
            cout << "📌 Hasil penjumlahan: " << bil1 + bil2 << endl;
            cout << "📌 Hasil pengurangan: " << bil1 - bil2 << endl;
            cout << "📌 Hasil perkalian: " << bil1 * bil2 << endl;
            if (bil2 != complex<double>(0, 0))
                cout << "📌 Hasil pembagian: " << bil1 / bil2 << endl;
            else
                cout << "❌ Error! Pembagian dengan nol tidak bisa dilakukan.\n";
            continue;
        }
        else {
            cout << "❌ Error! Operator tidak valid.\n";
            continue;
        }
        cout << "\033[1;36m----------------------------------------\033[0m\n";
        cout << fixed << setprecision(6); 
        string hasil;
        if (operasi == "+") {
            hasil = to_string(angka1) + " + " + to_string(angka2) + " = " + to_string(angka1 + angka2);
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "-") {
            hasil = to_string(angka1) + " - " + to_string(angka2) + " = " + to_string(angka1 - angka2);
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "*") {
            hasil = to_string(angka1) + " × " + to_string(angka2) + " = " + to_string(angka1 * angka2);
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "/") {
            if (angka2 != 0) {
                hasil = to_string(angka1) + " ÷ " + to_string(angka2) + " = " + to_string(angka1 / angka2);
                cout << "📌 Hasil: " << hasil << endl;
            } else {
                cout << "❌ Error! Pembagian dengan nol tidak bisa dilakukan.\n";
            }
        } else if (operasi == "^") {
            hasil = to_string(angka1) + " ^ " + to_string(angka2) + " = " + to_string(pow(angka1, angka2));
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "s") {
            if (angka1 >= 0) {
                hasil = "√" + to_string(angka1) + " = " + to_string(sqrt(angka1));
                cout << "📌 Hasil: " << hasil << endl;
            } else {
                cout << "❌ Error! Akar kuadrat dari bilangan negatif tidak bisa dihitung.\n";
            }
        } else if (operasi == "sin") {
            hasil = "sin(" + to_string(angka1) + "°) = " + to_string(sin(angka1 * M_PI / 180));
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "cos") {
            hasil = "cos(" + to_string(angka1) + "°) = " + to_string(cos(angka1 * M_PI / 180));
            cout << "📌 Hasil: " << hasil << endl;
        } else if (operasi == "tan") {
            if (fmod(angka1, 90) == 0 && fmod(angka1, 180) != 0) {
                cout << "❌ Error! tan(" << angka1 << "°) tidak terdefinisi.\n";
            } else {
                hasil = "tan(" + to_string(angka1) + "°) = " + to_string(tan(angka1 * M_PI / 180));
                cout << "📌 Hasil: " << hasil << endl;
            }
        } else if (operasi == "log") {
            if (angka1 > 0) {
                hasil = "log(" + to_string(angka1) + ") = " + to_string(log(angka1));
                cout << "📌 Hasil: " << hasil << endl;
            } else {
                cout << "❌ Error! Logaritma dari bilangan non-positif tidak bisa dihitung.\n";
            }
        } else if (operasi == "!") {
            if (angka1 < 0 || angka1 != (int)angka1) {
                cout << "❌ Error! Faktorial hanya bisa untuk bilangan bulat non-negatif.\n";
            } else {
                hasil = to_string((int)angka1) + "! = " + to_string(faktorial((int)angka1));
                cout << "📌 Hasil: " << hasil << endl;
            }
        }
        if (!hasil.empty()) {
            riwayat.push_back(hasil);
        }
        cout << "\033[1;36m----------------------------------------\033[0m\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (true);
    return 0;
}
