using namespace std;

class Buku;

class Proses{
    public:
        Proses(){}

        void toFile();
        void getData();
        void sortingAscending();

    private:
        ifstream ambil_data;
        ofstream tulis_data;
        Buku buku[100][100];
        string namaBuku[100];
        int jenisBuku, i, j, ambil, k;
};

void Proses::toFile(){
    tulis_data.open("apiData.txt");
    tulis_data << jenisBuku << endl;
    for(i=0;i<jenisBuku;i++){
        tulis_data << namaBuku[i] << endl;
    }
    for(i=0;i<jenisBuku;i++){
        for(j=0;j<3;j++){
            tulis_data << buku[i][j].kode << endl;
            if(i==jenisBuku-1 && j == 2){
                tulis_data << buku[i][j].judulBuku;
            }else{
                tulis_data << buku[i][j].judulBuku << endl;
            }
        }
    }
    tulis_data.close();
}

void Proses::getData(){
    ambil_data.open("apiData.txt");
    ambil = 1;
    while(!ambil_data.eof()){
        if(ambil == 1){
            ambil_data >> jenisBuku;
        }else if(ambil == 2){
            for(i=0;i<jenisBuku;i++){
                ambil_data >> namaBuku[i];
            }
        }else{
            for(i=0;i<jenisBuku;i++){
                for(j=0;j<3;j++){
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

void Proses::sortingAscending(){
    for(i=0;i<=jenisBuku;i++){
        for(j=0;j<2;j++){
            for(k=j+1;k<3;k++){
                if(buku[i][j].kode > buku[i][k].kode){
                Buku temp = Buku();
                temp.kode = buku[i][j].kode;
                buku[i][j].kode = buku[i][k].kode;
                buku[i][k].kode = temp.kode;

                temp.judulBuku = buku[i][j].judulBuku;
                buku[i][j].judulBuku = buku[i][k].judulBuku;
                buku[i][k].judulBuku = temp.judulBuku;
                }
            }
        }
    }
}