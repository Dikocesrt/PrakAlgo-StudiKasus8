using namespace std;

class Buku;

class Output{
    public:
        void getData();
        void cetak();

    private:
        ifstream ambil_data;
        string namaBuku[100];
        Buku book[100][100];
        int pil, jenisBuku, i, ambil, j;
};

void Output::getData(){
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
                    book[i][j] = Buku();
                    ambil_data >> book[i][j].kode;
                    ambil_data >> book[i][j].judulBuku;
                }
            }
        }
        ambil += 1;
    }
    ambil_data.close();
}

void Output::cetak(){
    cout << "========================================" << endl;
    cout << "Jenis Buku\t\t\tKode Buku\t\t\tJudul Buku" << endl;
    cout << "----------------------------------------" << endl;
    for(i=0;i<jenisBuku;i++){
        cout << namaBuku[i] << endl;
        for(j=0;j<3;j++){
            cout << "\t\t\t\t" << book[i][j].kode << "\t\t\t\t" << book[i][j].judulBuku << endl;
        }
    }
    cout << "========================================" << endl;
}