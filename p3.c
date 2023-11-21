#include<stdio.h>
#include<math.h>
#include<stdbool.h>
//PROTOTIPOS DE FUNCIONES//
void leerValores (int secuencia[10]);
int esMultiplo (int numero);
void secuenciaAlreves (int lista[]);
int calcularDistanciaMaxima (const int secuencia[]);
double media (const int secuencia[]);
void mostrarNumerosPerfectos (const int secuencia[]);
bool esPerfecto (const int num);



int main (){

        int lista[10];
        int max;
        double suma;

        leerValores (lista);    

        char opcion;

        while(0==0){

        printf("\nElija una opcion:\n1.Mostrar el primero multiplo de 3.\n2.Escribir la secuencia al reves.\n3.Calcular cual es la mayor distancia entre dos numeros consecutivos.\n4.Calcular la media de los numeros introducidos\n5. Mostrar los numeros perfectos que haya en la secuencia\n6.Salir\n\n");
        fflush(stdin);
        scanf("%c",&opcion);
        suma=0;
        max=0;

        switch(opcion)
        {
            case'1':
                esMultiplo(lista);
            break;


            case'2':
                    mostrarValoresReves (lista);
            break;

            case '3':
                    max=calcularDistanciaMaxima (lista);
                    printf("La mayor distancia entre dos numeros consecutivos es %d\n", max);

           break; 
            case '4':
                    suma= media(lista);
                    printf("\nLa media es %.2f\n", suma);
            
                break;
            case '5':

                mostrarNumerosPerfectos(lista);

                break;

            case '6': 
                    return 0;
            break;

            default: 
            printf("Error! Introduza una opcion valida.");
        
        }
    }
    return 0;
}


/// funciones///
void leerValores (int secuencia[10]){
            int i;
            for(i=0;i<=9;i++){
                printf("Escribe el valor %d: ", i+1);
                scanf("%d",&secuencia[i]);
                }
}

int encontrarMultiploDe3 (const int secuencia[]){
    int i;
    int multiplo;
    for(i=0;i<=9;i++){
        if(secuencia[i]%3==0 && secuencia[i]!=0){
            printf("\nEl primer multiplo de 3 es %d\n", secuencia[i]);
        }else{
            printf("\nNo hay multiplos de 3\n");
        }
    }
    return multiplo;
}


void mostrarValoresReves (const int secuencia[]){
     printf("\nLa secuencia al reves es: \n");
    for(int i=9; i>=0; i--){
        printf("%d\n", secuencia[i]);
        }
}


int calcularDistanciaMaxima (const int secuencia[]){
        int max=0;
        int resta=0;
        for(int i=0;i<=9;i++){
                resta=fabs(secuencia[i]-secuencia[i+1]);
                if(resta>max){
                max=resta;
                }
            
            }
return max;
}

double media (const int secuencia[]){
    double suma=0;
    for(int i=0; i<=9; i++){
                suma=suma+secuencia[i];
    }
    suma=suma/10;
    return suma;
}

void mostrarNumerosPerfectos (const int secuencia[]){
    int i;
    int sumadivisores;
    for (i=0,sumadivisores=0; i<=9; i++){
        if (esPerfecto(secuencia[i]))
            printf("El numero %d es perfecto\n", secuencia[i]);
        else
            sumadivisores++;
    }
    if (sumadivisores==10)
        printf("No hay ningun numero perfecto\n");

}

bool esPerfecto (const int num){
    int a, b;
    for (a=1, b=0; a<num; a++){
            if (num%a==0)
                b=b+a;
        }
    if (num==b && num!=0)
        return 1;
    else
        return 0;
}