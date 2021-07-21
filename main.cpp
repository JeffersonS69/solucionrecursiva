#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int cuentaCifras(int num) {
    int i = 1, cont = 0;
    if (num < 0) num = num * -1; //si es negativo, se lo hace positivo
    while (i <= num) {
        i = i * 10;
        cont++;
    }
    return cont;
}

bool primo(int num) {
    bool esPrimo = true;
    int i = 2;
    while (i <= num / 2 && esPrimo) {
        if (num % i == 0)
            esPrimo = false;
        i++;
    }
    return esPrimo;
}

int sumaprimos(int n) {
    int i = 1;
    int cont = 1;
    int sum = 0;
    while (i <= n) {
        cont++;
        if (primo(cont)) {
            sum += cont;
            i++;
        }
    }
    return sum;
}

int sumaprimosrecursivo(int limite, int n) {
    if (limite > 0) {
        if (primo(n))
            return sumaprimosrecursivo(limite - 1, n + 1) + n;
        else
            return sumaprimosrecursivo(limite, n + 1);
    } else

        return 0;
}

void adivinaElnumero(int oportunidades) {
    int num = 1 + rand() % 51;
//    int num=15;
    bool adivinaste = false;
    int n;
    cout << endl << "Adivina el NUMERO entre 1 y 50";
    int i = 1;
    while (i <= oportunidades && adivinaste == false) {
        cout << endl << endl << "OPORTUNIDA #: " << i;
        cout << endl << "Ingrese tu numero: ";
        cin >> n;
        if (n > num)
            cout << endl << "Debres ingresar un numero mas bajo...";
        else if (n < num)
            cout << endl << "Debes ingresar un numero mas alto...";
        else {
            cout << endl << "Felicidades, ganaste un pasaje a las galapagos...";
            adivinaste = true;
        }
        i++;
    }
    if (adivinaste)
        cout << endl << "ERES EL CAMPEON";
    else
        cout << endl << "PERDISTE, VUELVE HA INTENTARLO...";
}



int resultado_dado(){
    int dado= 1+ rand()%(6-1);
    return dado;
}

bool ganador_perdedor(int dado[], int cantidad_dados){
   int aux=0;
   int sum=0;
   bool resp=true;

    for(int i=0; i<cantidad_dados; i++ )
    {
        sum+=dado[i];
        if(i==0){
            aux=dado[i];
        }else{
            if(aux!=dado[i])
            {
                resp=false;
            }
        }
    }

    if(sum==11)
    {
        resp= true;
    }

    return resp;
}

void dibujar_asterisco(int dado[], int cantidad_dados){
    for(int i=0; i<cantidad_dados; i++ )
    {
        cout<<dado[i]<<":";
        for(int j=0; j<dado[i];j++){
            cout<<"*";
        }
        cout<<"  ---  ";
    }
}


void lanzar_dado(int oportu, int cantidad_dados){
    int dado[cantidad_dados-1];
    string pause;


    for(int x=0; x<oportu; x++) {
        cout<<"-----------------------------------"<<endl;
        cout << "OPORTUNIDA #: " << (x+1)<<endl;
        fflush(stdin);
        cout<<"Pulse la tecla ENTER para lanzar los dados"<<endl;
        getline(cin, pause);
        for (int i = 0; i < cantidad_dados; i++) {
            dado[i] = resultado_dado();
        }
        cout << "Valores de los dados" << endl;
        dibujar_asterisco(dado, cantidad_dados);
        cout << endl;
        if (ganador_perdedor(dado, cantidad_dados)){
            cout << "GANASTE"<<endl;
            break;
        }
        else
            cout << "PERDISTE"<<endl;
    }




}

int main() {
    //Juegos
    int opcion;
    srand(time(NULL));
    int num;
    do {
        cout <<endl << "MENU PRINCIPAL"<<endl;
        cout << "1. Adivinar un numero"<<endl;
        cout << "2. Lanzamiento Dados"<<endl;
        cout << "3. Cifras"<<endl;
        cout << "4. Suma numeros primos"<<endl;
        cout << "5. Salir..."<<endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                adivinaElnumero(5);
                break;
            case 2:
                lanzar_dado(2,3);
                break;
            case 3:
                cout<<"Ingrese varios numeros"<<endl;
                cin>>num;
                cout << "El numero " << num << "tiene " << cuentaCifras(num) << endl;
                if (primo(num)) {
                    cout << num << "Es primo";
                } else {
                    cout << num << "No es primo";
                }

                break;
            case 4:
                cout<<"Ingrese la cantidad de numeros primos a sumar"<<endl;
                cin>>num;
                cout << "La suma de los n primeros numeros primos es: : " << sumaprimos(num) << endl;

                cout << "La suma recursiva de los n primeros numeros primos es: : " << sumaprimosrecursivo(num, 2) << endl;
                break;
            case 5:
                cout << endl << "Hasta Luego"<<endl;
                break;
            default:
                cout << endl << "Opcion no valida"<<endl;
        }
    }while(opcion!=5);

    return 0;
}
