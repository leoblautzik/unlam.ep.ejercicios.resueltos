<<<<<<< HEAD
/*ARCHIVO productos.dat
    • Código (entero)
    • Precio (float)
    • Descripción (de hasta 50 caracteres) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*typedef struct
{
    int D,M,A;} TFecha;*/

typedef struct
{
    int cod;
    float pre;
    char descr[51];} TProd;

/*typedef struct
{
    int DNI;
    TFecha Fec;
    float impo;
    char Div[15];} TVenta;*/

int main()
{
    FILE *pf;
    int i;
    TProd prod, productos[78]={
                           {34995,1344,"Tirante de madera de pino 2 x 4 x 3.66 mts"},
{66739,995,"Cemento albañilería 40 kg"},
{96059,949,"Ladrillo de vidrio satinado"},
{98537,3659,"Vigueta Pretensada 3.40 m"},
{55316,1879,"Metal desplegado reforzado"},
{56834,158,"Ladrillo hueco portante 12 x 19 x 33 cm"},
{19833,2909,"Adhesivo tec glass 25 kg"},
{98437,9369,"Chapa de cincalum trapezoidal 27 x 3 mts"},
{20484,3909,"Policarbonato Alveolar 8 mm Cristal 1.05 x 1,45 m"},
{55521,2699,"Cumbrera de cincalum acanalada 25"},
{88323,2099,"Placa estandar 12,5 mm 120 x 240 cm"},
{48657,439,"Tornillo Aguja 6 x 1 x 10 u"},
{59741,4049,"Autoperforante Aguja 6 x 2 x 200 u"},
{15135,8309,"Perfil de chapa 100 x 50 x 1.6 mm x 6 m"},
{22109,2619,"Pintura asfáltica de secado rápido 4 l"},
{90618,1299,"Espuma simple 2 mm"},
{53536,8409,"Cinta autoadhesiva fitaflex 15 cm x 25 m"},
{52849,7969,"Cable unipolar 1.5 mm2 marrón 100 m"},
{32532,369,"Cinta aisladora Temflex 1550 negra 18 mm x 20m"},
{39397,849,"Caja capsulada 1 toma/tierra azul"},
{25239,579,"Juego de ficha K3/KH Pernos Chatos negra"},
{36621,869,"Set semi armado 1 interruptor + 1 tomacorriente"},
{18957,2979,"Llave térmica 2 x 25A 4.5KA"},
{95482,2319,"Caja para térmicas embutir 5 polos puerta Fume"},
{59032,5209,"Cablecanal superficie 100x45"},
{64433,199,"Grampa de Sujeción x 20 Unidades"},
{16861,32099,"Generador 2 HP Arranque manual nafta"},
{53730,1989,"Zapatilla eléctrica 6 tomas con 3 m de cable negra"},
{95315,4849,"Kit de herramientas Multipropósito 26 piezas"},
{28920,3149,"Secuenciador de cable utp"},
{59167,419,"Dado mecánico 1/2 x 12 mm"},
{67560,1529,"Fotocontrol universal fijo F5 1500 W 3 cables"},
{69737,34219,"Puerta de exterior Florencia 80 x 200 cm"},
{14612,7899,"Puerta plegable simil cedro 84 x 204 cm"},
{43229,14789,"Puerta plegable simil cedro 84 x 204 cm"},
{64682,359,"Punta perre.cuadrada 1/2 aluminio 33 x 73 mm"},
{20643,6669,"Persiana de aluminio Plata 160 x 165 cm"},
{55957,319,"Topes PVC para cortina de enrollar"},
{59221,1169,"Cinta para cortina de enrollar 4 m"},
{59211,779,"Mosquitero para ventana 130 x 150 cm"},
{21785,17679,"Claraboya base galvanizada 60 x 60 cm"},
{89690,17629,"Ventana de aluminio 80 x 40 cm blanca"},
{30481,899,"Guardacanto PVC Marfil 12 mm"},
{37342,1709,"Zócalo europeo nogal"},
{76433,1899,"Roseta Atr-195"},
{11461,329,"Curvas Atc-04 x 2 unidades"},
{88861,419,"Codo fusión 90° con rosca hembra 20 mm x 1/2"},
{39330,55,"Te normal 20 x 20 x 20 mm"},
{11118,2129,"Pileta de patio 5 entradas J.E. poliangular"},
{35131,559,"Codo Junta Elástica 110 x 90°"},
{75827,32999,"Grifería monocomando para cocina Vinaros cromo"},
{15831,59619,"Grifería monocomando para bidet Libby plateada"},
{16510,2399,"Cabezal no asc corto para lavatorio"},
{78934,33119,"Grifería bimando para bidet Cyrano Lever plateada"},
{18497,39499,"Tanque de agua Multicapa 850 l Arena"},
{85179,4179,"Indicador nivel tanque de agua"},
{87023,87899,"Bomba presurizadora SFL 20 1/2 HP"},
{57741,839,"Bolsa de arena gruesa para filtro de pileta"},
{18217,7799,"Eyector para bomba centrifuga"},
{43672,1359,"Control automático para tanque de agua con tanza"},
{61801,429,"Válvula esférica PVC 1/2"},
{35155,1269,"Válvula esférica metálica paso Total roja HH 1/2"},
{95071,82099,"Termotanque a gas 52 l"},
{26500,1249,"Reducción cónica de chapa galvanizada 75 mm x 100 mm"},
{22023,5349,"Extractor de aire 80m³/h"},
{96601,5559,"Pintura látex de interior blanco mate antimoho 20 L"},
{30751,2729,"Auriculares con cable DW-VCC401B negro"},
{87694,199,"Derivador caTV 5-1000mhz 4v"},
{93318,1079,"Botiquín n°2"},
{77827,1159,"Gancho Autoadhesivo Rectangular x 2 Unidades Metal"},
{58279,1099,"Espuma de poliuretano 300 ml"},
{73949,949,"Adhesivo para poliestireno expandido 250 gr"},
{82187,15099,"Carretilla chapa ruedas macizas 75 l"},
{51440,3299,"Columna pre armada 20 x 20 cm | 3 metros"},
{54008,1849,"Cabo para picos 90 cm"},
{11781,16149,"Cesto de basura a pedal 20 l acero inoxidable blanco"},
{32652,429,"Lámpara LED ECO 10 w 3000 K cálida"},
{29354,499,"Dicroica LED GU10 7 W luz día 38°"},


                           };

  /*  TVenta ventas[20]={
                           {11111111 ,1,1,2021,10.5,  "GAS"},
                           {11111111 ,1,2,2021,10.5,  "GAS"},
                           {11111111 ,1,3,2021,10.5,  "GAS"},
                           {11111111 ,1,4,2021,10.5,  "GAS"},
                           {11111111 ,1,5,2021,10.5,  "GAS"},
                           {11111111 ,1,6,2021,10.5,  "GAS"},
                           {11111111 ,1,7,2021,10.5,  "GAS"},
                           {11111111 ,1,8,2021,10.5, "GAS"},
                           {11111111 ,10,9,2021,10.5,"GAS"},
                           {11111111 ,12,10,2021,10.5,"GAS"},
                           {22222222,1,1,2021,20.5,   "GAS"},
                           {22222222,1,10,2021,20.5,  "GAS"},
                           {22222222,11,12,2021,15.3, "COMBUSTIBLE"},
                           {33333333,1,12,2021,20.5,  "GAS"},
                           {33333333,1,12,2021,20.5,  "GAS"},
                           {44444444,1,11,2021,30.5,  "GAS"},
                           {55555555,1,11,2021,30.5,  "PETRÓLEO"},
                           {77777777,2,12,2021,20.5, "GAS"},
                           {77777777,4,12,2021,20.5, "GAS"},
                           {77777777,2,12,2021,20.5, "PETRÓLEO"},


                        };*/
    setlocale (LC_ALL, "spanish");   //Configuración regional para aceptar el español

    pf=fopen("productos.dat","wb");

    if (pf==NULL)
    {
        printf("\n***Error al abrir el archivo.***");
        exit(1);
    }

    for (i=0; i<78; i++)
        fwrite(&productos[i],sizeof(TProd),1,pf);

    fclose(pf);



    pf=fopen("productos.dat","rb");

    if (pf==NULL)
    {
        printf("\n***Error al abrir el archivo.***");
        exit(1);
    }
    printf("\nCódigo\tPrecio\tDescripción\n");
    fread(&prod,sizeof(TProd),1,pf);
    while (!feof(pf))
        {
         printf("\n%-6d\t%-10.2f\t%-50s", prod.cod, prod.pre, prod.descr);
         fread(&prod,sizeof(TProd),1,pf);
        }

    fclose(pf);
}













=======
/*ARCHIVO productos.dat
    • Código (entero)
    • Precio (float)
    • Descripción (de hasta 50 caracteres) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*typedef struct
{
    int D,M,A;} TFecha;*/

typedef struct
{
    int cod;
    float pre;
    char descr[51];} TProd;

/*typedef struct
{
    int DNI;
    TFecha Fec;
    float impo;
    char Div[15];} TVenta;*/

int main()
{
    FILE *pf;
    int i;
    TProd prod, productos[78]={
                           {34995,1344,"Tirante de madera de pino 2 x 4 x 3.66 mts"},
{66739,995,"Cemento albañilería 40 kg"},
{96059,949,"Ladrillo de vidrio satinado"},
{98537,3659,"Vigueta Pretensada 3.40 m"},
{55316,1879,"Metal desplegado reforzado"},
{56834,158,"Ladrillo hueco portante 12 x 19 x 33 cm"},
{19833,2909,"Adhesivo tec glass 25 kg"},
{98437,9369,"Chapa de cincalum trapezoidal 27 x 3 mts"},
{20484,3909,"Policarbonato Alveolar 8 mm Cristal 1.05 x 1,45 m"},
{55521,2699,"Cumbrera de cincalum acanalada 25"},
{88323,2099,"Placa estandar 12,5 mm 120 x 240 cm"},
{48657,439,"Tornillo Aguja 6 x 1 x 10 u"},
{59741,4049,"Autoperforante Aguja 6 x 2 x 200 u"},
{15135,8309,"Perfil de chapa 100 x 50 x 1.6 mm x 6 m"},
{22109,2619,"Pintura asfáltica de secado rápido 4 l"},
{90618,1299,"Espuma simple 2 mm"},
{53536,8409,"Cinta autoadhesiva fitaflex 15 cm x 25 m"},
{52849,7969,"Cable unipolar 1.5 mm2 marrón 100 m"},
{32532,369,"Cinta aisladora Temflex 1550 negra 18 mm x 20m"},
{39397,849,"Caja capsulada 1 toma/tierra azul"},
{25239,579,"Juego de ficha K3/KH Pernos Chatos negra"},
{36621,869,"Set semi armado 1 interruptor + 1 tomacorriente"},
{18957,2979,"Llave térmica 2 x 25A 4.5KA"},
{95482,2319,"Caja para térmicas embutir 5 polos puerta Fume"},
{59032,5209,"Cablecanal superficie 100x45"},
{64433,199,"Grampa de Sujeción x 20 Unidades"},
{16861,32099,"Generador 2 HP Arranque manual nafta"},
{53730,1989,"Zapatilla eléctrica 6 tomas con 3 m de cable negra"},
{95315,4849,"Kit de herramientas Multipropósito 26 piezas"},
{28920,3149,"Secuenciador de cable utp"},
{59167,419,"Dado mecánico 1/2 x 12 mm"},
{67560,1529,"Fotocontrol universal fijo F5 1500 W 3 cables"},
{69737,34219,"Puerta de exterior Florencia 80 x 200 cm"},
{14612,7899,"Puerta plegable simil cedro 84 x 204 cm"},
{43229,14789,"Puerta plegable simil cedro 84 x 204 cm"},
{64682,359,"Punta perre.cuadrada 1/2 aluminio 33 x 73 mm"},
{20643,6669,"Persiana de aluminio Plata 160 x 165 cm"},
{55957,319,"Topes PVC para cortina de enrollar"},
{59221,1169,"Cinta para cortina de enrollar 4 m"},
{59211,779,"Mosquitero para ventana 130 x 150 cm"},
{21785,17679,"Claraboya base galvanizada 60 x 60 cm"},
{89690,17629,"Ventana de aluminio 80 x 40 cm blanca"},
{30481,899,"Guardacanto PVC Marfil 12 mm"},
{37342,1709,"Zócalo europeo nogal"},
{76433,1899,"Roseta Atr-195"},
{11461,329,"Curvas Atc-04 x 2 unidades"},
{88861,419,"Codo fusión 90° con rosca hembra 20 mm x 1/2"},
{39330,55,"Te normal 20 x 20 x 20 mm"},
{11118,2129,"Pileta de patio 5 entradas J.E. poliangular"},
{35131,559,"Codo Junta Elástica 110 x 90°"},
{75827,32999,"Grifería monocomando para cocina Vinaros cromo"},
{15831,59619,"Grifería monocomando para bidet Libby plateada"},
{16510,2399,"Cabezal no asc corto para lavatorio"},
{78934,33119,"Grifería bimando para bidet Cyrano Lever plateada"},
{18497,39499,"Tanque de agua Multicapa 850 l Arena"},
{85179,4179,"Indicador nivel tanque de agua"},
{87023,87899,"Bomba presurizadora SFL 20 1/2 HP"},
{57741,839,"Bolsa de arena gruesa para filtro de pileta"},
{18217,7799,"Eyector para bomba centrifuga"},
{43672,1359,"Control automático para tanque de agua con tanza"},
{61801,429,"Válvula esférica PVC 1/2"},
{35155,1269,"Válvula esférica metálica paso Total roja HH 1/2"},
{95071,82099,"Termotanque a gas 52 l"},
{26500,1249,"Reducción cónica de chapa galvanizada 75 mm x 100 mm"},
{22023,5349,"Extractor de aire 80m³/h"},
{96601,5559,"Pintura látex de interior blanco mate antimoho 20 L"},
{30751,2729,"Auriculares con cable DW-VCC401B negro"},
{87694,199,"Derivador caTV 5-1000mhz 4v"},
{93318,1079,"Botiquín n°2"},
{77827,1159,"Gancho Autoadhesivo Rectangular x 2 Unidades Metal"},
{58279,1099,"Espuma de poliuretano 300 ml"},
{73949,949,"Adhesivo para poliestireno expandido 250 gr"},
{82187,15099,"Carretilla chapa ruedas macizas 75 l"},
{51440,3299,"Columna pre armada 20 x 20 cm | 3 metros"},
{54008,1849,"Cabo para picos 90 cm"},
{11781,16149,"Cesto de basura a pedal 20 l acero inoxidable blanco"},
{32652,429,"Lámpara LED ECO 10 w 3000 K cálida"},
{29354,499,"Dicroica LED GU10 7 W luz día 38°"},


                           };

  /*  TVenta ventas[20]={
                           {11111111 ,1,1,2021,10.5,  "GAS"},
                           {11111111 ,1,2,2021,10.5,  "GAS"},
                           {11111111 ,1,3,2021,10.5,  "GAS"},
                           {11111111 ,1,4,2021,10.5,  "GAS"},
                           {11111111 ,1,5,2021,10.5,  "GAS"},
                           {11111111 ,1,6,2021,10.5,  "GAS"},
                           {11111111 ,1,7,2021,10.5,  "GAS"},
                           {11111111 ,1,8,2021,10.5, "GAS"},
                           {11111111 ,10,9,2021,10.5,"GAS"},
                           {11111111 ,12,10,2021,10.5,"GAS"},
                           {22222222,1,1,2021,20.5,   "GAS"},
                           {22222222,1,10,2021,20.5,  "GAS"},
                           {22222222,11,12,2021,15.3, "COMBUSTIBLE"},
                           {33333333,1,12,2021,20.5,  "GAS"},
                           {33333333,1,12,2021,20.5,  "GAS"},
                           {44444444,1,11,2021,30.5,  "GAS"},
                           {55555555,1,11,2021,30.5,  "PETRÓLEO"},
                           {77777777,2,12,2021,20.5, "GAS"},
                           {77777777,4,12,2021,20.5, "GAS"},
                           {77777777,2,12,2021,20.5, "PETRÓLEO"},


                        };*/
    setlocale (LC_ALL, "spanish");   //Configuración regional para aceptar el español

    pf=fopen("productos.dat","wb");

    if (pf==NULL)
    {
        printf("\n***Error al abrir el archivo.***");
        exit(1);
    }

    for (i=0; i<78; i++)
        fwrite(&productos[i],sizeof(TProd),1,pf);

    fclose(pf);



    pf=fopen("productos.dat","rb");

    if (pf==NULL)
    {
        printf("\n***Error al abrir el archivo.***");
        exit(1);
    }
    printf("\nCódigo\tPrecio\tDescripción\n");
    fread(&prod,sizeof(TProd),1,pf);
    while (!feof(pf))
        {
         printf("\n%-6d\t%-10.2f\t%-50s", prod.cod, prod.pre, prod.descr);
         fread(&prod,sizeof(TProd),1,pf);
        }

    fclose(pf);
}













>>>>>>> 116dce8d25dde7f4eb5ceabf7b81a6068cca1e21
