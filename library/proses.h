using namespace std;

class Buku;

class Proses{
    public:
        Proses(){}

        void toFile();
        void getData();
        void transform();
        void sortingAscending();

    private:
        ifstream ambil_data;
        ofstream tulis_data;
        Buku buku[100][100];
        Buku newBook[100];
        string namaBuku[100];
        int jenisBuku, i, j, ambil, newIndex;
};

void Proses::toFile(){
    tulis_data.open("apiData.txt");
    tulis_data << jenisBuku << endl;
    for(i=0;i<jenisBuku;i++){
        tulis_data << namaBuku[i] << endl;
    }
    for(i=0;i<=newIndex;i++){
        tulis_data << newBook[i].kode << endl;
        if(i==newIndex){
            tulis_data << newBook[i].judulBuku;
        }else{
            tulis_data << newBook[i].judulBuku << endl;
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

void Proses::transform(){
    for(i=0;i<jenisBuku;i++){
        for(j=0;j<3;j++){
            newIndex = (i * 3) + j;
            newBook[newIndex].kode = buku[i][j].kode;
            newBook[newIndex].judulBuku = buku[i][j].judulBuku;
        }
    }
}

void Proses::sortingAscending(){
    for(i=0;i<=newIndex;i++){
        for(j=0;j<=(newIndex-i-1);j++){
            if(newBook[j].kode > newBook[j+1].kode){
                Buku temp = Buku();
                temp.kode = newBook[j].kode;
                newBook[j].kode = newBook[j+1].kode;
                newBook[j+1].kode = temp.kode;

                temp.judulBuku = newBook[j].judulBuku;
                newBook[j].judulBuku = newBook[j+1].judulBuku;
                newBook[j+1].judulBuku = temp.judulBuku;
            }
        }
    }
}