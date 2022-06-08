#include<iostream>
#include<fstream>
#include "library/Buku.h"
#include "library/input.h"
#include "library/proses.h"
#include "library/output.h"
using namespace std;

int main(){
    Input objectInput = Input();
    Proses objectProses = Proses();
    Output objectOutput = Output();
    
    objectInput.masukin();
    objectInput.toFile();

    objectProses.getData();
    objectProses.sortingAscending();
    objectProses.toFile();

    objectOutput.getData();
    objectOutput.cetak();

    return 0;
}
