using namespace std;

class Buku;

class Proses{
    public:
        Proses(){}

        void toFile(string namaFile){
            tulis_data.open(namaFile);
                tulis_data << jumlahKaryawan << endl;
                for(i=0;i<jumlahKaryawan;i++){
                    tulis_data << karyawan[i].id << endl;
                    tulis_data << karyawan[i].nama << endl;
                    tulis_data << karyawan[i].jabatan << endl;
                    if(i == jumlahKaryawan - 1){
                        tulis_data << karyawan[i].noTelepon;
                    }else{
                        tulis_data << karyawan[i].noTelepon << endl;
                    }
                }
            tulis_data.close();
        }

        void getData(){
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
                            buku[i] = Buku();
                            ambil_data >> buku[i].kode;
                            ambil_data >> buku[i].judulBuku;
                        }
                    }
                }
                ambil += 1;
            }
            ambil_data.close();
        }

        void sortingAscending(){
            for(i=0;i<jumlahKaryawan;i++){
                for(j=0;j<(jumlahKaryawan-i-1);j++){
                    if(karyawan[j].id > karyawan[j+1].id){
                        Karyawan temp = Karyawan();
                        temp.id = karyawan[j].id;
                        karyawan[j].id = karyawan[j+1].id;
                        karyawan[j+1].id = temp.id;

                        temp.nama = karyawan[j].nama;
                        karyawan[j].nama = karyawan[j+1].nama;
                        karyawan[j+1].nama = temp.nama;

                        temp.jabatan = karyawan[j].jabatan;
                        karyawan[j].jabatan = karyawan[j+1].jabatan;
                        karyawan[j+1].jabatan = temp.jabatan;

                        temp.noTelepon = karyawan[j].noTelepon;
                        karyawan[j].noTelepon = karyawan[j+1].noTelepon;
                        karyawan[j+1].noTelepon = temp.noTelepon;
                    }
                }
            }
            toFile("karyawanAscending.txt");
        }


    private:
        ifstream ambil_data;
        ofstream tulis_data;
        Buku buku[100][100];
        string namaBuku[100];
        int jenisBuku, i, j, ambil;
};