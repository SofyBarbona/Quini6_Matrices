#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///  Ejercicio Integrador Vectores y Matrices: Realizar un programa que simule el comportamiento del juego de azar, Quini 6.
///El jugador compra una boleta con 6 números, del 0 al 45, los puede elegir o comprar de forma aleatoria, no puede tener números repetidos.

///Se realiza la primer jugada, es decir, salen 6 números aleatorios, no repetidos, entre el 0 y el 45. Si el jugador acierta los 6 números gana 5 millones de pesos.
///Si solo acierta 5 números el jugador gana 200mil pesos, si acierta 4 de los números el jugador gana 500 pesos.

///Se realiza la revancha, aquí el jugador gana solo si acierta los 6 números, gana un total de 2 millones de pesos.

///Luego se realiza la 3er jugada, donde se sortean otros 6 números. Aquí el jugador gana un millón, 100mil o 2mil pesos si acierta 6, 5 o 4 números respectivamente.

///Por ultimo, se juntan los 3 sorteos, 18 números en total. Si el jugador tiene 6 números de esos 18 gana un total de mil pesos.

///Realizar un menú que permita comprar la boleta, e ir realizando los sorteos para ver si se gana o no algo en cada sorteo.
///Realizar un bucle que repita el sorteo hasta que se gane el pozo de los 6 aciertos en la primer jugada. El bucl termina cuando se acertaron todos los números,
///debe mostrar por pantalla los números, lo que gano y la cantidad de sorteos que pasaron para que gane.


int main()
{
    srand(time(0));
    int boleta[6], tradicional[6], revancha[6],siempresale[6],pozoextra[18];
    int frecuencia, respuesta, aciertos, GANO5MILLONES, contador,cantidadsorteos;

    ///Bienvenida
    GANO5MILLONES=0;
    respuesta=1;

    while(GANO5MILLONES!=1){
    printf("\n----------------------------------------\n");
    printf("Bienvenido al quini 6!");

        if (respuesta==1 || respuesta==2){
        ///COMPRAR LA BOLETA
        printf("\nPRESIONE 1: Para poder elegir los numeros \n");
        printf("PRESIONE 2: Para que se elijan aleatoriamente\n");
        printf("PRESIONE 3: Para hacerlo aleatoriamente hasta ganar\n");
        scanf("%d",&respuesta);
        }

        switch(respuesta){
            case 1:
                ///Elegir los numeros
                for (int i=0;i<6;i++){
                    do{
                        printf("Ingrese el valor %d",i+1);
                        printf(": \n");
                        scanf("%d",&boleta[i]);
                        frecuencia=1;
                        for (int g=0;g<i;g++){
                            if (i!=0 && (boleta[i]==boleta[g])){
                                frecuencia=frecuencia+1;
                            }
                        }
                    }while((boleta[i]<0 || boleta[i]>45) || frecuencia>1); //asegura que sean del 0 al 45 y que no se repita
                }
                break;
            case 2:
                ///Al azar
                for (int i=0;i<6;i++){
                    do{
                        boleta[i]=rand()%46;
                        frecuencia=1;
                        for (int g=0;g<i;g++){
                            if (i!=0 && (boleta[i]==boleta[g])){
                                frecuencia=frecuencia+1;
                            }
                        }
                    }while(frecuencia>1);
                }
                break;
            case 3:
                ///Al azar x siempre
                for (int i=0;i<6;i++){
                    do{
                        boleta[i]=rand()%46;
                        frecuencia=1;
                        for (int g=0;g<i;g++){
                            if (i!=0 && (boleta[i]==boleta[g])){
                                frecuencia=frecuencia+1;
                            }
                        }
                    }while(frecuencia>1);
                }
                respuesta=3;
        }

        //MOSTRAR BOLETA
        printf("\nSu boleta es: \n");
        for (int i=0;i<6;i++){
            printf(" %d",boleta[i]);
        }
        printf("\n----------------------------------------\n");

        ///TRADICIONAL - PRIMER JUGADA
        printf("\nComienza la tirada tradicional\n");
        //sorteo
        for (int i=0;i<6;i++){
                do{
                    tradicional[i]=rand()%46;
                    frecuencia=1;
                    for (int g=0;g<i;g++){
                        if (i!=0 && (tradicional[i]==tradicional[g])){
                            frecuencia=frecuencia+1;
                        }
                    }
                }while(frecuencia>1);
        }
        //mostrar
        for (int i=0;i<6;i++){
            printf(" %d",tradicional[i]);
        }
        //ver si gano
        aciertos=0;
        for (int i=0;i<6;i++){
            for (int g=0;g<6;g++){
                if (boleta[i]==tradicional[g]){
                    aciertos=aciertos+1;
                }
            }
        }
        printf(" ACIERTOS: %d",aciertos);
        //premio
        switch (aciertos){
            case 6: printf ("\nHas ganado 5 MILLONES DE PESOS!!!");
                    GANO5MILLONES=1;
                    break;
            case 5: printf ("\nHas ganado 200 mil pesos");
                    break;
            case 4: printf ("\nHas ganado 500 pesos");
                    break;
            default: printf ("\nNo has ganado nada en la tradicional");
        }
        printf("\n----------------------------------------\n");

        ///REVANCHA
        if (aciertos!=6){
            printf("\nSe realiza la revancha\n");
            //sorteo
            for (int i=0;i<6;i++){
                do{
                    revancha[i]=rand()%46;
                    frecuencia=1;
                    for (int g=0;g<i;g++){
                        if (i!=0 && (revancha[i]==revancha[g])){
                            frecuencia=frecuencia+1;
                        }
                    }
                }while(frecuencia>1);
            }
            //mostrar
            for (int i=0;i<6;i++){
                printf(" %d",revancha[i]);

            }
            //ver si gano
            aciertos=0;
            for (int i=0;i<6;i++){
                for (int g=0;g<6;g++){
                    if (boleta[i]==revancha[g]){
                        aciertos=aciertos+1;
                    }
                }
            }
            printf(" ACIERTOS: %d",aciertos);
            //premio
            if (aciertos==6){
                printf("\nHAS GANADO 2 MILLONES DE PESOS\n");
            }else{
                printf("\nNo has ganado la revancha\n");
                }
        }
        printf("\n----------------------------------------\n");

        ///SIEMPRE SALE
        if (aciertos!=6){
             printf("\nSe realiza el SIEMPRE SALE\n");
            //sorteo
            for (int i=0;i<6;i++){
                do{
                    siempresale[i]=rand()%46;
                    frecuencia=1;
                    for (int g=0;g<i;g++){
                        if (i!=0 && (siempresale[i]==siempresale[g])){
                            frecuencia=frecuencia+1;
                        }
                    }
                }while(frecuencia>1);
            }
            //mostrar
            for (int i=0;i<6;i++){
                printf(" %d",siempresale[i]);

            }
            //ver si gano
            aciertos=0;
            for (int i=0;i<6;i++){
                for (int g=0;g<6;g++){
                    if (boleta[i]==siempresale[g]){
                        aciertos=aciertos+1;
                    }
                }
            }
            printf(" ACIERTOS: %d",aciertos);
            //premio
            switch (aciertos){
                case 6: printf ("\nHas ganado 1 MILLON DE PESOS!!!");
                        GANO5MILLONES=1;
                        break;
                case 5: printf ("\nHas ganado 100mil pesos");
                        break;
                case 4: printf ("\nHas ganado 2mil pesos");
                        break;
                case 3: printf ("\nHas ganado 500 pesos");
                        break;
                case 2: printf ("\nHas ganado 100 pesos");
                        break;
                case 1: printf ("\nHas ganado 50 pesos");
                        break;
                default: printf ("\nNo has ganado nada en el SIEMPRE SALE");
            }
        }
        printf("\n----------------------------------------\n");
        ///POZO EXTRA

        if (aciertos!=6){
            printf("\nSe realiza el pozo extra\n");
            //sorteo
                for (int i=0;i<6;i++){
                    pozoextra[i]=tradicional[i];
                    pozoextra[i+6]=revancha[i];
                    pozoextra[i+12]=siempresale[i];
                }
            //mostrar
            for (int i=0;i<18;i++){
                printf(" %d",pozoextra[i]);

            }
            //ver si gano
            contador=0;
            aciertos=0;
            for (int i=0;i<6;i++){
                for (int g=0;g<18;g++){
                    if (boleta[i]==pozoextra[g]){
                        contador=contador+1;
                        aciertos=aciertos+1;
                    }
                }
                if(contador>=2){
                    aciertos=aciertos-(contador-1);
                }
                contador=0;
            }
            printf(" ACIERTOS: %d",aciertos);
            //premio
            if (aciertos==6){
                printf("\nHAS GANADO MIL PESOS DE PESOS\n");
            }else{
                printf("\nNo has ganado el pozo extra\n");
                }


        }

        ///FIN
        cantidadsorteos=cantidadsorteos+1;
    }
    printf("\nLa cantidad de sorteos fueron: %d\n",cantidadsorteos);
    return 0;
}
