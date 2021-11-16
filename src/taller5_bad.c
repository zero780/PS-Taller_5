
#include <stdio.h>
#include <stdlib.h>

char *mesg[2] = {"Par", "impar"} ;




typedef struct estTDA{
        int c;
        int *arr;
        int cant_arr;
        char *mensaje;
}est;

void mostrar_est(est *a);
void mostrar_int(int *a);
int *mas(int cant);


int *mas(int cant){

        int arr[cant];
        int *b = (int *)arr;

        int i = 0;

        for(i = 0; i < cant; i++){
                b[i]  = i *10;
        }

        return arr;



}

void mostrar_est(est *a){
        int i = 0;
        for(i = 0; i < sizeof(a)/sizeof(est); i++){
                printf("\nEst c: %d, mensaje: %s\n", (a+i)->c, (a+i)->mensaje);
                mostrar_int((a+i)->arr);
                printf("\n");
        }

}

void mostrar_int(int *a){
        int i = 0;
        char *z = (char *)a;
        for(i = 0; i < sizeof(z)/sizeof(int); i++){
                printf("%d\n", *(z+i));
        }
}


int *fn1(int cant, int mul){
        int buf[cant];

        int i = 0;
        for(i = 0; i < cant; i++){
                buf[i] = mul*i;
        }

        return &buf[0];
 }

void fn2(int cant, est **res){
        est *data = malloc(sizeof(est *)*cant);

        if(data == NULL){
                return;
        }


        int i = 0;
        for(i = 0; i <= cant ; i++){
                (data+i)->c = i;
                data[i].arr = fn1(i,3);
                data[i].cant_arr = i;
                (data+i)->mensaje = mesg[ i % 2 ];

        }

        *res = (est *)&data;

}

int main(int argc, char **argv){

        if(argc < 2){
                printf("Uso: ./programa <numero de elemenetos>\n");
                exit(EXIT_FAILURE);
        }

        int cant = atoi(argv[1]);


        int *arr = fn1(cant, 2);

        est *res = NULL;
        fn2(cant, &res);

        mostrar_int(arr);
        int *arr2 = mas(cant);
        mostrar_est(res);
        mostrar_int(arr2);

        exit(EXIT_SUCCESS);
}