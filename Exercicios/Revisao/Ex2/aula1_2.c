#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float r, float *area, float *volume);
int raizes(float a, float b, float c, float *x1, float *x2);
int pares(int n, int *vet);
void inverte(int n, int *vet);
double avalia(double *poli, int grau, double x);

// 2.1 ------------------------------------------------------
// int main()
// {
//     int r;
//     float *area, *volume;

//     area = (float *)malloc(sizeof(float));
//     volume = (float *)malloc(sizeof(float));

//     printf("Digite o tamanho do raio da esfera: ");
//     scanf("%d", &r);

//     calc_esfera(r, area, volume);

//     printf("Area da Superfície: %0.2f\n", *area);
//     printf("Volume da Esfera: %0.2f\n", *volume);

//     free(area);
//     free(volume);

//     return 0;
// }

// // 2.2 --------------
// int main()
// {
//     float a, b, c, *x1, *x2;
//     int qtdRaiz;

//     x1 = (float *)malloc(sizeof(float));
//     x2 = (float *)malloc(sizeof(float));

//     printf("Digite o valor de 'a' 'b' e 'c': ");
//     scanf("%f %f %f", &a, &b, &c);

//     qtdRaiz = raizes(a, b, c, x1, x2);

//     if (qtdRaiz == 0)
//     {
//         printf("Não há raízes nessa equação\n");

//         return 0;
//     }

//     printf("Quantidade de raízes: %d\nX1: %.2f\nX2: %.2f\n", qtdRaiz, *x1, *x2);
//     free(x1);
//     free(x2);
//     return 0;
// }

//2.3 ---------------
// int main()
// {
//     int n, qtdPares;

//     printf("Quantidade de numeros do vetor: ");
//     scanf("%d", &n);

//     int *vet;
//     vet = (int *)calloc(sizeof(int), n);

//     for (int i = 0; i < n; i++)
//     {
//         printf("Vet[%d] = ", i);
//         scanf("%d", &*(vet + i));
//     }
//     qtdPares = pares(n, vet);
//     free(vet);

//     printf("Quantidade de numeros pares do vetor: %d\n", qtdPares);
//     return 0;
// }

// 2.4 ---------------
// int main()
// {
//     int n = 4, *vet, num;
//     vet = (int *)calloc(sizeof(int), n);

//     printf("Quantidade de numeros do vetor: ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         printf("Vet[%d] = ", i);
//         scanf("%d", &*(vet + i));
//     }

//     inverte(n, vet);

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", *(vet + i));
//     }
//     free(vet);
//     return 0;
// }

//2.5 -----------------

int main(void)
{
    int grau;
    double *poli, x, avaliaResult;

    printf("Digite o grau da equação: ");
    scanf("%d", &grau);

    poli = (double *)calloc(sizeof(double), (grau + 1));
    for (int i = grau, k = 0; i >= 0; i--, k++)
    {
        printf("Digite o %do coeficiente: ", k + 1);
        scanf("%lf", &*(poli + i));
    }

    printf("Digite o x da equacao: ");
    scanf("%lf", &x);

    avaliaResult = avalia(poli, grau, x);
    free(poli);
    printf("Avaliacao: %.2lf\n", avaliaResult);
}

void calc_esfera(float r, float *area, float *volume)
{
    //Area Superficie
    *area = 4 * (3.14) * (r * r);

    //Volume
    *volume = *area / 3;
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
    int qtd = 2, delta;

    //Delta
    delta = (b * b) - (4 * a * c);

    if (delta < 0)
    {
        qtd = 0;
        return qtd;
    }
    //Raízes
    *x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
    *x2 = ((-1 * b) - sqrt(delta)) / (2 * a);

    if (delta == 0)
    {
        qtd = 1;
        return qtd;
    }

    return qtd;
}

int pares(int n, int *vet)
{
    int qtd = 0;

    //Verifica Se eh Par
    for (int i = 0; i < n; i++)
    {
        if ((*(vet + i)) % 2 == 0)
            qtd++;
    }

    return qtd;
}

void inverte(int n, int *vet)
{
    int aux;
    int i = 0, j = n - 1;

    //Inverte Vetor
    while (i < j)
    {
        aux = *(vet + i);
        *(vet + i) = *(vet + j);
        *(vet + j) = aux;
        i++;
        j--;
    }
}

double avalia(double *poli, int grau, double x)
{
    double avalia = 0.0;
    double valorDx = x;

    //Inicia Avaliacao com o numero de coeficiente de grau 1
    avalia = *(poli);

    //Calcula a Avaliacao total
    for (int i = 1; i <= grau; i++)
    {
        avalia += *(poli + i) * valorDx;
        valorDx *= x;
    }

    return avalia;
}
