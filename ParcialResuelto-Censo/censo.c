#include<stdio.h>
#include<string.h>

int cargarCensistas(int[], char[][26], int[], int);
//void cargarPersonasPorVivienda(int [], int [], int [], int[][5], int);
//( 1 )
void ordenarCensistas(int [], char [][26], int [], int []);
void listarCensistas1(int [], char [][26], int [], int []);
//( 2 )
void listarCensistas2(int [], char [][26], int [], int []);
//( 3 )
void mostrarpersonasViviendaZona(int [][5]); 
//( 4 )
void informarPromedioHabCensados(int []);
//( 5 )
void informarZonaMenosHab(int [][5], int [], char [][26]);

int leerYvalidar(int inf, int sup, char mensaje[])
{    
    int dato;
    do
    {
        printf("%s",mensaje);
        scanf("%d", &dato);
    } while (dato < inf || dato > sup);
    return dato;
}

int leerYvalidarConExit(int inf, int sup, int exit, char mensaje[])
{    
    int dato;
    do
    {
        printf("%s",mensaje);
        scanf("%d", &dato);
    } while (dato != 0 && (dato < inf || dato > sup));
    return dato;
}

int buscarDNI(int dni, int dnis[], int cantCensistas)
{
    int pos = -1;
    int i = 0;
    while (i < cantCensistas && pos == -1)
    {
        if(dnis[i] == dni)
            pos = i;
        i++;
    }
    return pos;
}


int main()
{
    int dni, pos, zona, dnis [50];
    char apenoms[50][26];
    int zonaAsignada[50];
    int personasPorCensista[50];
    int personasViviendaZona[5][5];

    for(int i=0; i<50; i++)
        personasPorCensista[i]=0;
    
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            personasViviendaZona[i][j]=0;

    int cantCensistas = cargarCensistas(dnis, apenoms,zonaAsignada, 50);
    printf("%d\n", cantCensistas);
    
    dni = leerYvalidarConExit(999, 60000000, 0, "\nIngrese DNI: ");
    while(dni != 0)
    {
        pos = buscarDNI(dni, dnis, cantCensistas);
        if (pos == -1)
        {
            pos = cantCensistas + 1; 
            cantCensistas ++;
            dnis[pos] = dni;
            printf("Ingrese Apenom: ");
            fgets(apenoms[pos], 26, stdin);
            zonaAsignada[pos] = leerYvalidar(11, 15, "Ingrese la zona: ");
        }

        zona = zonaAsignada[pos];
        for( int i=0; i < 5; i++)
        {
            int cant = leerYvalidar(0, 1000, "Ingrese cant");
            personasPorCensista[pos] += cant;
            personasViviendaZona[zona-1][i] += cant;
        }

        dni = leerYvalidarConExit(999, 60000000, 0, "\nIngrese DNI: ");
    }
    
    
    //cargarPersonasPorVivienda(dnis, zonaAsignada, personasPorCensista, personasViviendaZona, cantCensistas);
    /*//( 1 )
    ordenarCensistas(dnis, apenoms, zonaAsignada, personasPorCensista);
    listarCensistas1(dnis, apenoms, zonaAsignada, personasPorCensista);
    //( 2 )
    listarCensistas2(dnis, apenoms, zonaAsignada, personasPorCensista);
    //( 3 )
    mostrarpersonasViviendaZona(personasViviendaZona); 
    //( 4 )
    informarPromedioHabCensados(personasPorCensista);
    //( 5 )
    informarZonaMenosHab(personasViviendaZona, zonaAsignada, apenoms);
    */
    return 0;

}


int cargarCensistas(int dnis[], char apenoms [][26], int zonaAsignada [], int max)
{
    int i = 0;
    int dni,zona ;
    dni = leerYvalidar(999, 60000000, "\nIngrese DNI: ");
    while(dni != 999 && i < max)
    {
        dnis[i] = dni;
        getchar();
        printf("Ingrese Apenom: ");
        fgets(apenoms[i], 26, stdin);
        zonaAsignada[i] = leerYvalidar(11, 15, "Ingrese la zona: ");
        dni = leerYvalidar(999, 60000000, "\nIngrese DNI: ");
        i++;
    }

    return i;    
}


/*void cargarPersonasPorVivienda(int dnis[], int zonaAsignada[], int personasPorCensista[], int personasViviendaZona[][5], int cs)
{
    int i = 0;
    int dni, pos, zona;
    dni = leerYvalidarConExit(999, 60000000, 0, "\nIngrese DNI: ");
    pos = buscarDNI(dni, dnis, cs);
    if (pos == -1)
    {
        pos = cs + 1;
        cantCensistas ++;
    }
    
    zona = zonaAsignada[pos];

*/


}
