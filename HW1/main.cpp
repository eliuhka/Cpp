
#include <iostream>
#include <math.h>

float ruudu_ymberm66t_raadiuse_j2rgi(float kyljepikkus)
{
    return 4*kyljepikkus;
}
float ruudu_pindala_raadiuse_j2rgi(float kyljepikkus)
{
    return pow(kyljepikkus, 2);
}
float ringi_ymberm66t_raadiuse_j2rgi(float raadius)
{
    return 2*M_PI*raadius;
}
float ringi_pindala_raadiuse_j2rgi(float raadius)
{
    return M_PI*pow(raadius, 2);
}
float palga_arvutamine(float raha)
{
    return raha+(raha*0.05);
}

int main()

{
    int nr; //ülesande number mida hakatakse kuvama
    printf("sisesta ylesande nr 1-3");
    scanf ("%d" , &nr);


   if (nr ==1)
    {
        int r; //raadius
        int x; //serva pikkus
        float ruuduymberm66t;
        float ruudupindala;
        float ringiymberm66t;
        float ringipindala;
        printf("Enter radius of circle");
        scanf("%d", &r);
        x = 2 * r;

        ruuduymberm66t =  ruudu_ymberm66t_raadiuse_j2rgi(x);
        ringiymberm66t = ringi_ymberm66t_raadiuse_j2rgi(r);
        ruudupindala = ruudu_pindala_raadiuse_j2rgi(x);
        ringipindala = ringi_pindala_raadiuse_j2rgi(r);


        printf("ruudu umberm66t on %.1f", ruuduymberm66t);
        printf(" ringi ymberm66t on %.1f", ringiymberm66t);
        printf(" ruudu pindala on %.1f", ruudupindala);
        printf(" ringi pindala on %.1f", ringipindala);

        return 0;

    }




   else if (nr==2)
    {
        float palk;
        float uus_palk;

        printf("sisesta palga suurus");
        scanf("%f" , &palk);

        if (palk < 1000)
        {
            uus_palk = palga_arvutamine(palk);
            printf("Said palga k6rgendust, sinu uus palk on %.2f eurot", uus_palk);
        }
        else
        {
            printf("Sinu palk on niigi suur, sa ei saanud palga k6rgendust :(");
            return 0;
        }
    }




    else if (nr==3)
    {
        int temp;

        printf("sisesta temperatuur");
        scanf("%d", &temp);


            if (temp < 10)
            {
                printf("temperature is COLD!");
            }
            else if (temp > 25)
            {
                printf("temperature is HOT!") ;
            }
            else
            {
                printf("temperature is WARM!")  ;
            }
    }
    else
    {
        printf("Task failed succesfully!");
    }



}