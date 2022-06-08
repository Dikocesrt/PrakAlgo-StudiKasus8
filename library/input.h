using namespace std;

class Buku;

class Input{
    public:
        Input(){}
        void masukin();
        void toFile();

    private:
        ofstream tulisData;
        Buku buku[100][100];
        string namaBuku[100];
        int jenisBuku, i, j;
};

void Input::masukin(){
    cout << "Program Menginput Buku Perpustakaan" << endl;
    cout << "========================================" << endl;
    cout << "Masukkan Jumlah Jenis Buku : ";
    cin >> jenisBuku;
    cout << "========================================" << endl;
    for(i=0;i<jenisBuku;i++){
        cout << "Masukkan Jenis Buku ke " << i << " : ";
        cin >> namaBuku[i];
    }
    cout << "========================================" << endl;
    for(i=0;i<jenisBuku;i++){
        cout << "Jenis Buku = " << namaBuku[i] << endl;
        cout << "--------------------------" << endl;
        for(j=0;j<3;j++){
            buku[i][j] = Buku();
            cout << "Masukkan Kode Buku : ";
            cin >> buku[i][j].kode;
            cout << "Masukkan Judul Buku : ";
            cin >> buku[i][j].judulBuku;
            cout << "--------------------------" << endl;
        }
        cout << "========================================" << endl;
    }
}

void Input::toFile(){
    tulisData.open("apiData.txt");
    tulisData << jenisBuku << endl;
    for(i=0;i<jenisBuku;i++){
        tulisData << namaBuku[i] << endl;
    }
    for(i=0;i<jenisBuku;i++){
        for(j=0;j<3;j++){
            tulisData << buku[i][j].kode << endl;
            if(i==jenisBuku-1 && j == 2){
                tulisData << buku[i][j].judulBuku;
            }else{
                tulisData << buku[i][j].judulBuku << endl;
            }
        }
    }
    tulisData.close();
}