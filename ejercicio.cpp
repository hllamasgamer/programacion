#include<iostream>

using namespace std;

int main(){
  float nota;
    cout<<"Ingrese la nota del estudiante: ";
    cin>>nota;
    if (nota >= 9) {
        cout << "Sobresaliente" << endl;
    }else if (nota >= 7 && nota <= 9){
        cout << "notable" << endl;
    }else if (nota >= 5 && nota < 7){
        cout << "Aprobado" << endl;
    }else {
        cout << "Suspennso" << endl;
    }
        return 0;
    }
