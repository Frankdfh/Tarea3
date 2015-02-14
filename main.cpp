#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <vector>          // std::list
#include <set>          // std::list
#include <map>          // std::list
using namespace std;


//Agrega valor (dado) a mi_mapa (dado), en la llave dada
//Nota: mi_mapa es un apuntador, para usarlo se sugiere desrreferenciarlo con el operador *
//Explicacion: Llamamos al apuntador dentro de parentesis y asignamos el valor junto con la llave.
void asignarValor(map<string,int> *mi_mapa, string llave,int valor)
{
    (*mi_mapa) [llave]= valor;
}

//Devuelve el valor asociado a la llave (dada) en mi_mapa (dado)
//Explicacion: Este ejercicio se resuelve unicamente llamando al mapa por medio de la variable llave
char obtenerValor(map<int,char> mi_mapa,int llave)
{
    return mi_mapa[llave];
}

//Devolver el un mapa con los siguientes valores dados en la tabla
//  LLave     |   Valor
//----------------------------
//  1         |   "lunes"
//  2         |   "martes"
//  3         |   "miercoles"
//  4         |   "jueves"
//  5         |   "viernes"
//  6         |   "sabado"
//  7         |   "domingo"
//Explicacion: Este ejercicio se resolvio unicamente agregando los datos de la tabla al mapa
map<string,int> obtenerSemana()
{
    map<string,int> semana;
    semana["lunes"]=1;
    semana["martes"]=2;
    semana["miercoles"]=3;
    semana["jueves"]=4;
    semana["viernes"]=5;
    semana["sabado"]=6;
    semana["domingo"]=7;
    return semana;
}

//devuelve la interseccion de mi_set1 (dado) y mi_set2 (dado)
//(devuelve un set que contenga unicamente los valores que mi_set1 y mi_set2 tengan en comun)
//Explicacion: Utilize un ciclo while anidado a otro ciclo while, para recorer ambos set al mismo tiempo
//y de esa manera comparar cada valor del set1 con cada valor del set2, si los numeros son iguales, se inserta en el set3
set<int> getInserseccion(set<int> mi_set1, set<int> mi_set2)
{
    set<int> mi_set3;
    set<int> ::iterator i=mi_set1.begin();
    while(i!=mi_set1.end())
    {
        set<int> ::iterator j=mi_set2.begin();
        while(j!=mi_set2.end())
        {
            if(*i==*j)
            {
              mi_set3.insert(*i);
            }
            j++;
        }
        i++;
    }
    return mi_set3;
}

//devuelve la union de mi_set1 (dado) y mi_set2 (dado)
//(devuelve un set que contenga todos los valores de mi_set1 y mi_set2)
//Explicacion: Cree un iterator "i" para recorrer el set 1 con el ciclo while, y mediante lo vaya recorriendo
//tambien vaya ingresando el elemento al set3, luego cree un iterator "j" para recorrer igualmente el set2
//y tambien irlo agregando al set 3, luego unicamente se retorna el set3.
set<int> getUnion(set<int> mi_set1, set<int> mi_set2)
{
    set<int> mi_set3;
    set<int> ::iterator i=mi_set1.begin();
    while(i!=mi_set1.end())
    {
        mi_set3.insert(*i);
        i++;
    }
    set<int> ::iterator j=mi_set2.begin();
    while(j!=mi_set2.end())
    {
        mi_set3.insert(*j);
        j++;
    }
    return mi_set3;
}

//devuelve true si mi_sub_set (dado) es un subconjunto de mi_set (dado)
//(mi_set contiene todos los valores de mi_sub_set)
//Explicacion: Se creo un doble ciclo anidado cada uno con un iterator diferente para recorrer ambos set
// se compara cada elemento del sub_set con cada elemento del set, si son iguales entonses se le suma +1
// a la variable conteo, si el valor de conteo es = al tamano del set significa que los valores sel sub_set
// si estan dentro del set primario.
bool esSubConjunto(set<int> mi_set, set<int> mi_sub_set)
{
    set<int> ::iterator i=mi_sub_set.begin();
    int conteo=0; // Variable contador
    while(i!=mi_sub_set.end())
    {
        set<int>::iterator j=mi_set.begin();
        while(j!=mi_set.end())
        {
            if(*i==*j)
            {
              conteo++;
            }
            j++;
        }
        if(conteo==mi_sub_set.size())
        {
            return true;
        }
        i++;
    }
    return false;
}

int main ()
{

    //Funcion evaluadora
    evaluar();
    return 1;
}
