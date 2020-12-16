#include <iostream>  // Di gunakan untuk menjalankan perintah input dan output. seperti cin, cout.
#include <windows.h> // untuk library sleep
#include <time.h>  // untuk library time
#include <conio.h> //untuk library getch

using namespace std; //Menggunakan skope std seperti std::cin std::cout

int menu(){//Tampilan awal menu pilihan
    int pilihan;
    system("cls");
    cout << endl << endl;
    cout << "   =========Smart Band========"<< endl;
    cout << "   || 1. Clock              ||\n";
    cout << "   || 2. Monitoring Kalori  ||\n";
    cout << "   || 3. Deteksi Heart Rate ||\n";
    cout << "   || 4. Blanja OL          ||\n";
    cout << "   || 5. Stopwatch          ||\n";
    cout << "   || 6. Exit               ||\n";
    cout << "   ==========================="<<endl;
    cout << "   => ";
    cin >> pilihan;
    return pilihan;
}

void waktu(){
    system ("cls");
    int sec_prev=0;
        while(1)
        {
            int detik, menit, jam;

            //Menyimpan total detik
            time_t total_detik = time(0);

            //Mendapatkan nilai detik, menit, jam
            struct tm* ct = localtime(&total_detik);

            detik   = ct->tm_sec;
            menit   = ct->tm_min;
            jam     = ct->tm_hour;

            //Menampilkan hasil
            if(detik==sec_prev+1 || (sec_prev==59 && detik==0))
            {
                system("CLS");
                cout << "\n\n";
                cout << "    ====CLOCK====\n";
                cout << "   |"<< jam <<" : "<< menit << " : " << detik <<"|" <<endl;
                cout << "    =============\n";
            }
            sec_prev=detik;//untuk menyimpan detik detik sebelumnya
        }
   }

void monitoring(){
    system ("cls");
    int jarak, langkah;
    double kalori;

        cout << "   Langkah : ";
        cin >> langkah;
        jarak  = langkah/3;
        kalori = jarak*80/1000;
        cout << "   Meter   : "<< jarak << " m" << endl;
        cout << "   Kalori  : " << kalori <<" cal"<< endl<<endl;
        cout << "   Tekan untuk kembali ke menu utama." << endl;
        system("pause");
        system("cls");
        menu();
}

void heart_rate(){
    system ("cls");
        int detak;
        char telp;
        cout << "   Deteksi hearth rate\n";
        cout << "     Kencangkan band.. \n\n";
        cout << " Tekan apa saja untuk mulai\n";
        system ("pause");
        for(int i=60;i<=100;i++){//menampilkan tampilan memindai
            cout<<endl<<"   Scanning . . . "<<i<<"%"<<endl;
            system("cls");
            }
        detak = 40+rand()%200;//random dari 40 - 200
        cout << "\n\n" << "     Detak jantung anda : " << detak << " BPM"<< endl;
            switch(detak){
                case 0 ... 59:
                    cout<<"     => Detak jantung anda terlalu rendah. mohon segera istirahat. "<<endl<<endl;
                    cout<<"        Telepon dokter spesialis jantung ? (y\n) \n";
                    cin >> telp;
                        if((telp == 'y') | (telp == 'Y')){
                            cout << "Telepon dokter dan mengirim riwayat kesehatan...";
                        }else ((telp == 'n') | (telp == 'N'));
                break;
                case 60 ... 100:
                    cout<<"     => Dalam kondisi normal."<<endl;
                break;
                case 101 ... 999:
                    cout<<"     => Detak jantung anda terlalu tinggi. mohon segera istirahat. "<<endl<<endl;
                    cout<<"        Telepon dokter spesialis jantung ? (y/n) \n";
                    cin >> telp;
                        if((telp == 'y') | (telp == 'Y')){
                            cout << "\tTelepon dokter dan mengirim riwayat kesehatan...";
                        }else ((telp == 'n') | (telp == 'N'));
                break;
                }
        cout << endl;
        cout << "   Tekan untuk kembali ke menu utama." << endl;
    system("pause");
    system("cls");
    menu();
}

void Blanja_Online(){
    system ("cls");
    int total=0, jumlah,bayar, i, total2=0;
    int pilihan [10];
    int kalori [10];
        cout << "Belanja Online"<< endl << endl;
        cout << "1. Good day\t:\tRp. 6000" << endl;
        cout << "2. Soda\t\t:\tRp. 5000" << endl;
        cout << "3. Teh Botol\t:\tRp. 4000" << endl;
        cout << "4. Susu\t\t:\tRp. 5500" << endl << endl;
        cout << "==========================================================="<<endl;
        cout << "Berapa produk yang anda pilih : ";
        cin >> jumlah;
            for (int i = 1; i <= jumlah; i++ ){
                cout << "Pilihan " << i << ": " << endl;
                cin >> pilihan [i];
                    if (pilihan[i] == 1){
                        cout << "Membeli Good Day"<<endl<<endl;
                        pilihan[i] = 6000;
                        kalori [i] = 179;
                   }else if (pilihan[i] == 2){
                        cout << "Anda Membeli Soda"<<endl<<endl;
                        pilihan[i] = 5000;
                        kalori [i] = 100;
                   }else if (pilihan[i] == 3){
                        cout << "Anda Membeli Teh Botol"<<endl<<endl;
                        pilihan[i] = 4000;
                        kalori [i] = 85;
                   }else if (pilihan[i] == 4){
                        cout << "Anda Membeli Susu"<<endl<<endl;
                        pilihan[i] = 5500;
                        kalori [i] = 80;
                   }else{
                       cout << "Input Anda Salah";
                    }
            }

        for(i=1; i<=jumlah; i++){
            total=total+pilihan[i];
        }
        cout<<"Totalnya : " << total << endl;

        for(i=1; i<=jumlah; i++){
            total2=total2+kalori[i];
        }
        cout << "Dengan   : " << total2 << " Kalori" <<endl<<endl;
        cout << "Masukan Pembayaran anda : ";
        cin  >> bayar;
            if (bayar >= total){
                bayar=bayar-total;
                cout << "Kembalian anda : " << bayar << endl;}

        cout << endl;
        cout << "Tekan untuk kembali ke menu utama" << endl;
        system("pause");
        system("cls");
        menu();
    }

void stopwatch(){
    system("cls");
    int Jam=0,Menit=0,Detik=0;
        cout<<"             Stopwatch"<<endl;
        cout<<"           HH : MM : SS"<<endl;
        cout<<"             "<<Jam<< " : "<<Menit<<" : "<< Detik <<endl<<endl;
        cout<<"         Tekan untuk memulai\n"<<endl;
        getch();

        while(!kbhit()){
        Detik++;
        Sleep(1000);

            if(Detik>59){
                Menit++;
                Detik=0;}

            if(Menit>59){
                Jam++;
                Menit=0;}

        system("cls");
        cout<<"             Stopwatch"<<endl;
        cout<<"             "<<Jam<< " : "<<Menit<<" : "<< Detik <<endl<<endl;
        cout<<"     Tekan apa saja untuk pause"<<endl;
        }
        getch();

        cout<<"        Waktu setelah pause"<< endl;
        cout<<"             "<<Jam << " : "<<Menit<<" : "<< Detik <<endl<<endl;
        getch();

    cout << "Tekan untuk kembali ke menu utama" << endl;
    system("pause");
    system("cls");
    menu();
}

int main(){//Fungsi menjalankan program.

int pilih = menu();

    while(pilih!=6){

        switch (pilih){
            case 1 :
                waktu();
            break;
            case 2 :
                monitoring();
            break;
            case 3 :
                heart_rate();
            break;
            case 4 :
                Blanja_Online();
            break;
            case 5 :
                stopwatch();
            break;
            default:
                cout << endl;
                cout << "Pilihan tidak ditemukan." << endl;
                system("pause");
            break;
            }
    system("cls");
    pilih = menu();
    }
}
