#include <iostream>
using namespace std;

// Fonction récursive pour calculer le PGCD de deux entiers
int pgcd(int a, int b) {
    // Partie "ancre" : condition d'arrêt
    if (b == 0)
        return a;
    // Partie "récursive"
    else
        return pgcd(b, a % b);
}

int main() {
    int a, b;

    cout << "=== Calcul du PGCD de deux entiers ===" << endl;
    cout << "Entrez le premier entier : ";
    cin >> a;
    cout << "Entrez le deuxième entier : ";
    cin >> b;

    cout << "Le PGCD de " << a << " et " << b << " est : " << pgcd(a, b) << endl;

    return 0;
}
