#include <iostream>
#include <iomanip> //para establecer la precision y el formato cientifico

using namespace std;

void CV(double alpha[], int n){ //funcion para el calculo de los coeficientes, la formula Cardano-Vieta

    //array para guardar los coeficientes
    double coef[n+1]={0};

    //El coeficiente que precede a x^n siempre va a ser 1,de lo contrario, el polinomio no seria de grado n
    coef[n]=1;

    //la formula de Cardano-Vieta se calculara con un bucle
    for(int i=1;i<=n;i++){//la variable i recorre los elementos del array alpha
        for(int j=n-i-1;j<n;j++){// la variable j los coeficientes del polinomio
            coef[j]=coef[j]+(-1)*alpha[i-1]*coef[j+1];
        }
    }//alpha[] es equivalente a las sumas S_i que se explican en el pdf

    cout<<"\nCoeficientes del polinomio, desde an_1 hasta a0: ";
    for(int i=n;i>=0;i--){
        cout<<scientific<<setprecision(8)<<coef[i]<< " , ";
    }
}

int main(){


    int n=0; //solicitar al usuario el grado del polinomio
    cout<<"Introduzca el grado del polinomio: "<<endl;
    cin>>n;


    if(n<1){//lanza error si el grado es menor que 1
        cout<<"\nEl grado es menor que uno."<<endl;
        return 0;
    }

    double alpha[n]; //se almacena los coeficientes en un array
    cout<<"\nIntroduzca las raices del polinomio: "<<endl;
    for(int i=0;i<n;i++){
        cin>>alpha[i];
    }

    CV(alpha, n); //se invoca funcion void en la principal

    return 0;
}
