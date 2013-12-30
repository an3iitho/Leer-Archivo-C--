#include <iostream>
#include <fstream>
using namespace std;

void cargaFichero(char* direccion){
    //Crea una variable archivo de ruta del archivo con parametro para leer tipo binario
    //ifstream solo lectura
    ifstream archivo (direccion, ios::in|ios::binary);
    //Verifica si el archivo se puede abrir
    if (archivo.is_open()){
        //Se mueve 0 espacios desde la ultima posicion del archivo
        archivo.seekg(0, ios::end);
        //tam contiene el numero total de caracteres
        int tam = (archivo.tellg());
        //contenido un arreglo de caracteres del tamaño de tam
        char *contenido = new char [tam];
        //Limpia la cadena a utilizar
        for(int i = 0; i <= (tam+1); i++){
            contenido[i] = '\0';
        }
        //se mueve 0 posiciones desde el inicio
        archivo.seekg (0, ios::beg);
        //read extrae un numero de caracteres (tam) del archivo y lo ingresa en el arreglo de caracteres
        archivo.read (contenido, tam);
        //Cierra en buffer del archivo
        archivo.close();
        //Muestra el contenido en pantalla
        cout << "\nCONTENIDO: \n" << contenido << endl;
        //Elimina el arreglo utilizado
        delete [] contenido;
    }
}

int main(){
    char* direccion = "leerFichero.cpp";
	cargaFichero(direccion);
}
