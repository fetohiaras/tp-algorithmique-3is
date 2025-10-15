# tp-algorithmique-3is
## Exercice 4 
## 4.1 — Proposition d’un algorithme récursif pour le PGCD

### Notations
- `a` et `b` : deux entiers positifs (non nuls)
- `PGCD(a, b)` : le plus grand commun diviseur de `a` et `b`


### Partie “ancre” (cas de base)
Lorsque `b = 0`, le calcul s’arrête :
> PGCD(a, 0) = a

C’est la condition d’arrêt de la récursion.  
Cela signifie que dès que le second nombre devient nul, le PGCD est le premier nombre.

---

### Partie “récursive”
Sinon, on applique la propriété mathématique du PGCD (algorithme d’Euclide) :

> PGCD(a, b) = PGCD(b, a % b)

où `%` désigne le reste de la division entière.

La fonction s’appelle elle-même avec des valeurs plus petites jusqu’à atteindre le cas de base.



### Étapes du raisonnement récursif
1. Si `b == 0` → retourner `a`
2. Sinon → appeler récursivement `PGCD(b, a % b)`



### Exemple de déroulement
Calcul de  PGCD(35, 45) :

Appel récursif | Calcul effectué | Résultat partiel 
PGCD(35, 45)   | → PGCD(45, 35) | - |
PGCD(45, 35)   | → PGCD(35, 10) | - |
PGCD(35, 10)   | → PGCD(10, 5)  | - |
PGCD(10, 5)    | → PGCD(5, 0)   | - |
PGCD(5, 0)     | retourne 5     | Résultat final = 5 |

### Résumé
- Cas de base : `PGCD(a, 0) = a`
- Cas récursif : `PGCD(a, b) = PGCD(b, a % b)`
- Cet algorithme s’appuie sur le principe de division euclidienne et permet d’obtenir le PGCD efficacement.
