/*
 * Este programa fue realizado como la tarea#8 el 13 de septiembre de 2018,
 * para la clase de fundamentos de programación.
 *
 * Su proposito es determinar el Indice de masa corporal de una persona, dados su peso y su altura
 * ya sea en sistema decimal o ingles, al igual que proporcionar en que nivel de peso corresponde.
 *
 * Fecha: 13 de septiembre de 2018
 * Autor: Eduardo Parga Vela
 * Correo: A01411896@itesm.mx
 */
#include <stdio.h>
#include <math.h>

//Funcion que hace el calculo del IMC.
double calculaBMI(double H, double W){
    double result;
    result=W/pow(H,2);
    return result;
}

//Funcion que captura el peso en kg.
double capturaWD(){
    double weight;
    printf("Escribe tu peso.");
    scanf("%lf", &weight);
    return weight;
}

//Funcion que captura la altura en m.
double capturaHD(){
    double height;
    printf("Escribe tu altura.");
    scanf("%lf", &height);
    return height;
}

//Funcion que captura el peso en lb.
double capturaWI(){
    double weight;
    printf("Escribe tu peso.");
    scanf("%lf", &weight);
    return weight / 2.20462;
}

//Funcion que captura la altura en pies y pulgadas.
double capturaHI(){
    double heightF;
    printf("Escribe tu altura en pies y pulgadas.");
    scanf("%lf", &heightF);
    return heightF / 3.28;
}

//Funcion que muestra el valor del IMC y en que rango corresponde.
void nivelPeso (double BMI){
    printf("El indice de masa corporal es de %lf\n", BMI);
    printf("Que corresponde a un nivel de peso");
    if (BMI < 18.5) printf(" Bajo");
    else if (BMI >= 18.5 && BMI <= 24.9) printf(" Normal");
    else if (BMI >= 25.0 && BMI <= 29.9) printf(" Sobrepeso");
    else if (BMI >= 30.0) printf(" Obeso");
}

int main(void) {
    // calculadora de IMC
    double BMI;
    int opcion;
    double height, weight;

    //El usuario selecciona en que sistema de unidades quiere sacar su IMC.
    printf("¿En que sistema de unidades quieres calcular tu IMC?\n");
    printf("1. Sistema metrico decimal.\n");
    printf("2. Sistema Ingles\n");
    scanf("%i", &opcion);


    do {
        //La opcion elegida sera enviada a este switch.
        switch (opcion) {
            case 1: //Si se eligio el sistema decimal...
                printf("Proporciona el valor del peso en kg y la altura en m.\n");
                height = capturaHD(); //El valor de height corresponde al resultado de la funcion capturaHD
                weight = capturaWD(); //El valor de weight corresponde al resultado de la funcion capturaWD
                BMI = calculaBMI(height, weight); //El valor de bmi corresponde al resultado de la funcion calculaBMI, dados los valores de height y weight.
                break;
            case 2: //Si se eligio el sistema ingles...
                printf("Proporciona el valor del peso en lb y la altura en ft y in.\n");
                height = capturaHI(); //El valor de height corresponde al resultado de la funcion capturaHI
                weight = capturaWI(); //El valor de weight corresponde al resultado de la funcion capturaWI
                BMI = calculaBMI(height, weight); //El valor de bmi corresponde al resultado de la funcion calculaBMI, dados los valores de height y weight.
                break;
            default:
                printf("Entrada invalida, selecciona la opción 1 o 2");
        }
    } while (opcion < 1 || opcion > 2 ); //El ciclo se cierra si el valor de opcion no es ni 1 ni 2.
    nivelPeso (BMI);
    return 0;
}