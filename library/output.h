using namespace std;

class Buku;

class Output{
    public:
        void getData(string namaFile);
        void cetak();

    private:
        ifstream ambil_data;
        Buku buku[100][100];
        int pil, jenisBuku, i, ambil, j;
};

void Output::getData(string namaFile){
    ambil_data.open(namaFile);
    ambil = 1;
    while(!ambil_data.eof()){
        if(ambil == 1){
            ambil_data >> jenisBuku;
        }else{
            for(i=0;i<jenisBuku;i++){
                for(j=0;j<jenisBuku;j++){
                    buku[i][j] = Buku();
                    ambil_data >> buku[i][j].kode;
                    ambil_data >> buku[i][j].judulBuku;
                }
            }
        }
        ambil += 1;
    }
    ambil_data.close();
}

void Output::cetak(){
    getData("apiData.txt");
    cout << "Jenis Buku\t\t\tKode Buku\t\tJudul Buku" << endl;
    cout << "Novel\t\t\t";
    for(i=0;i<1;i++){
        for(j=0;j<jenisBuku;j++){
            cout << buku[i][j].kode << "\t\t\t" << buku[i][j].judulBuku << endl;
        }
    }
    cout << endl;
    cout << "Komik\t\t\t";
    for(i=1;i<2;i++){
        for(j=0;j<jenisBuku;j++){
            cout << buku[i][j].kode << "\t\t\t" << buku[i][j].judulBuku << endl;
        }
    }
    cout << endl;
    cout << "Ensiklopedi\t\t\t";
    for(i=2;i<3;i++){
        for(j=0;j<jenisBuku;j++){
            cout << buku[i][j].kode << "\t\t\t" << buku[i][j].judulBuku << endl;
        }
    }
    cout << endl;
    cout << "Dongeng\t\t\t";
    for(i=3;i<4;i++){
        for(j=0;j<jenisBuku;j++){
            cout << buku[i][j].kode << "\t\t\t" << buku[i][j].judulBuku << endl;
        }
    }
}