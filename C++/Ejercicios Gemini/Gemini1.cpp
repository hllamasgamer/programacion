#include <iostream>
#include <string>
using namespace std;

class Personaje {
    protected:
    int vida;
    int vidaMax;
    int fuerza;

    public:
    string nombre;

    Personaje (string n, int v){
        nombre = n;
        vida = v;
        vidaMax = v;
    }
    void recibirDanio (int cantidad){
        vida = vida - cantidad;
        cout<< nombre << " ha recibido " << cantidad << " de daño!" << endl;
        cout << "Vida restante: " << vida << endl;
    };

    void curar (int cantidad){
        vida = vida + cantidad;
        if (vida > vidaMax) {
            vida = vidaMax;
        }
        cout<< nombre << " se ha sido curado por " << cantidad << " puntos!" << endl;
        cout << "Vida actual: " << vida << endl;
    }

    virtual void atacar() {
        cout << nombre << " realiza un ataque básico!" << endl;
    }
};

class Mago : public Personaje {
    public:
    int mana;

    Mago(string n, int v, int m) : Personaje(n, v) {
        mana = m;
    }

    void atacar () override {
        cout << nombre << " lanza un ataque con su arco!" << endl;
        mana = mana - 10;
    }
};

class Enemigo : public Personaje {
    public:
        Enemigo(string n, int v): Personaje(n, v) {

        }
    void atacar () override {
        cout << "¡El Monstruo " << nombre << " te muerde!" << endl;
    }
};

int main () {

    Personaje miHeroe ("Rean", 100);
    Mago miMaga ("Alisa", 80, 50);
    Enemigo slime ("Slime", 40);
    slime.atacar();
    miHeroe.recibirDanio(15);
    miHeroe.curar(20);
    slime.atacar();
    miMaga.recibirDanio(25);
    miMaga.curar(30);
    miMaga.atacar();

    slime.recibirDanio(40);

    return 0;
}